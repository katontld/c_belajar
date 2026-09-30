# Proyek C (Panduan VS Code - Windows)

Panduan praktis menjalankan kodingan bahasa C langsung dari **Terminal VS Code** di Windows.

---

## 🚀 Langkah Menjalankan di VS Code

1. **Buka Terminal VS Code:**
   * Tekan shortcut: ``Ctrl + ` `` (tombol petik miring di sebelah angka 1)
   * Atau lewat menu atas: **Terminal** > **New Terminal**

2. **Compile Kodingan:**
   Ketik perintah berikut lalu tekan Enter:
   ```powershell
   gcc main.c -o main.exe
   ```

3. **Jalankan Program:**
   Ketik perintah berikut:
   ```powershell
   .\main.exe
   ```

---

## 🔄 Cara Ambil Update Kodingan Terbaru
Tiap kali ada update kodingan, cukup buka Terminal VS Code dan ketik:
```powershell
git pull
```
Lalu compile dan jalankan lagi (`gcc main.c -o main.exe` dan `.\main.exe`).
