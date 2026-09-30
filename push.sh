#!/bin/bash

# Default commit message jika tidak diisi
pesan="${1:-update kodingan: $(date '+%Y-%m-%d %H:%M:%S')}"

echo "🚀 [1/3] Menambahkan semua perubahan (git add)..."
git add .

# Cek apakah ada perubahan yang perlu di-commit
if git diff --staged --quiet; then
    echo "⚠️ Tidak ada perubahan yang perlu di-commit."
    exit 0
fi

echo "📦 [2/3] Membuat commit: \"$pesan\"..."
git commit -m "$pesan"

echo "⬆️ [3/3] Mengunggah ke GitHub (git push)..."
git push

echo "✅ Beres! Kodingan terbaru sudah berhasil di-push ke GitHub."
