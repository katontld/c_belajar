/*
 * Tugas 3 - Pengolahan Bahasa Lanjut
 * Nama : Andre Dwi Kurnia Atmaja
 * NIU  : 578416
 * NIM  : 26_578416_TK_65827
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_DIGITS 10
#define BUFFER_CAPACITY 4096
#define FILE_INPUT_PATH "input.txt"
#define FILE_OUTPUT_PATH "output.json"

// Struct untuk menyimpan data frekuensi kemunculan angka
typedef struct {
    unsigned long long frequency[NUM_DIGITS];
    unsigned long long total_digits;
    unsigned long long total_noise_chars;
} DigitStats;

// Inisialisasi struct statistik pada heap memory
DigitStats* inisialisasi_stats(void) {
    DigitStats *stats = (DigitStats *)calloc(1, sizeof(DigitStats));
    if (stats == NULL) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori untuk statistik.\n");
        return NULL;
    }
    return stats;
}

// Membersihkan alokasi memori dinamis untuk mencegah memory leak
void bersihkan_stats(DigitStats **stats_ptr) {
    if (stats_ptr != NULL && *stats_ptr != NULL) {
        free(*stats_ptr);
        *stats_ptr = NULL;
    }
}

// Membaca file input.txt dan menghitung frekuensi angka 0-9
bool proses_file_input(const char *nama_file, DigitStats *stats) {
    // Validasi pembukaan file input
    FILE *file_in = fopen(nama_file, "r");
    if (file_in == NULL) {
        perror("Error saat membuka file input");
        return false;
    }

    // Alokasi buffer memori dinamis untuk membaca data per chunk
    char *buffer = (char *)malloc(BUFFER_CAPACITY * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Error: Gagal mengalokasikan buffer pembacaan.\n");
        fclose(file_in);
        return false;
    }

    size_t bytes_read = 0;

    // Membaca isi file secara bertahap
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_CAPACITY, file_in)) > 0) {
        for (size_t i = 0; i < bytes_read; ++i) {
            char ch = buffer[i];

            // Filter karakter angka saja (0-9)
            if (ch >= '0' && ch <= '9') {
                int digit_index = ch - '0';
                stats->frequency[digit_index]++;
                stats->total_digits++;
            } else if (ch != '\r' && ch != '\n') {
                stats->total_noise_chars++;
            }
        }
    }

    // Bebaskan memory buffer dan tutup file input
    free(buffer);
    buffer = NULL;
    fclose(file_in);

    return true;
}

// Menyimpan hasil perhitungan ke file output.json dengan format JSON yang valid
bool tulis_file_output_json(const char *nama_file, const DigitStats *stats) {
    FILE *file_out = fopen(nama_file, "w");
    if (file_out == NULL) {
        perror("Error saat membuat file output");
        return false;
    }

    fprintf(file_out, "{\n");
    for (int i = 0; i < NUM_DIGITS; ++i) {
        // Elemen terakhir (angka 9) tidak menggunakan tanda koma di akhir
        if (i < NUM_DIGITS - 1) {
            fprintf(file_out, "  \"%d\": %llu,\n", i, stats->frequency[i]);
        } else {
            fprintf(file_out, "  \"%d\": %llu\n", i, stats->frequency[i]);
        }
    }
    fprintf(file_out, "}\n");
    fclose(file_out);
    return true;
}

int main(void) {
    // Alokasi memori dinamis
    DigitStats *stats = inisialisasi_stats();
    if (stats == NULL) {
        return EXIT_FAILURE;
    }

    // Baca dan hitung digit dari input.txt
    if (!proses_file_input(FILE_INPUT_PATH, stats)) {
        bersihkan_stats(&stats);
        return EXIT_FAILURE;
    }

    // Simpan hasil ke output.json
    if (!tulis_file_output_json(FILE_OUTPUT_PATH, stats)) {
        bersihkan_stats(&stats);
        return EXIT_FAILURE;
    }

    printf("Perhitungan selesai. Hasil telah disimpan ke %s\n", FILE_OUTPUT_PATH);
    bersihkan_stats(&stats);
    return EXIT_SUCCESS;
}
