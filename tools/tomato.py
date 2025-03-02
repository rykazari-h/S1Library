import os
import time
import threading
import pygame
import tkinter as tk
from tkinter import filedialog

class Nyanpass:
    def __init__(self, root):
        self.root = root
        self.root.title("nyanpass")
        self.time_label = tk.Label(root, text="25:00", font=("Arial", 24))
        self.time_label.pack(pady=20)
        self.sound_button = tk.Button(root, text="select", command=self.Choose)
        self.sound_button.pack(pady=5)

        # タイマー設定
        self.study_time = 25 * 60
        self.break_time = 5 * 60
        self.time_remaining = self.study_time
        self.is_study_session = True
        self.running = False

        # デフォルトの音声ファイル
        self.sound_path = os.path.join(os.getcwd(), "nyanpass.mp3")

        pygame.mixer.init()

        self.Start()

    def Start(self):
        if not self.running:
            self.running = True
            threading.Thread(target=self.countdown, daemon=True).start()

    def countdown(self):
        while self.time_remaining > 0:
            mins, secs = divmod(self.time_remaining, 60)
            self.time_label.config(text=f"{mins:02}:{secs:02}")
            self.root.update()
            time.sleep(1)
            self.time_remaining -= 1

        self.Switch()

    def Switch(self):
        self.is_study_session = not self.is_study_session
        self.time_remaining = self.study_time if self.is_study_session else self.break_time

        self.Play()

        self.running = False
        self.Start()

    def Choose(self):
        file_path = filedialog.askopenfilename(
            title="サウンドファイルを選択",
            filetypes=[("Audio Files", "*.mp3;*.wav;*.ogg")]
        )
        if file_path:
            self.sound_path = file_path
            print(f"current音声: {self.sound_path}")

    def Play(self):
        if os.path.exists(self.sound_path):  # ファイルが存在するかチェック
            pygame.mixer.music.load(self.sound_path)
            pygame.mixer.music.play()

if __name__ == "__main__":
    root = tk.Tk()
    app = Nyanpass(root)
    root.mainloop()
