@echo off
cd /d "C:\Program Files (x86)\Electronic Arts\L'Ascesa del Re Stregone"
taskkill /F /IM lotrbfme2ep1.exe 2>nul
taskkill /F /IM game.dat 2>nul
timeout /t 1 /nobreak >nul
start "" "lotrbfme2ep1.exe" -noshellmap -win -xres 1280 -yres 720