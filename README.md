# XOR Encryption – C++ WebAssembly

Prosta aplikacja webowa umożliwiająca szyfrowanie i deszyfrowanie tekstu za pomocą operacji XOR. Algorytm został zaimplementowany w języku C++, skompilowany do WebAssembly (WASM) i zintegrowany z interfejsem HTML oraz JavaScript.

## ✨ Funkcje

- Szyfrowanie tekstu za pomocą operacji XOR.
- Deszyfrowanie wygenerowanych szyfrogramów.
- Automatyczne rozpoznawanie szyfrogramów na podstawie prefiksu `XOR1:`.
- Kodowanie szyfrogramu w formacie Base64.
- Obsługa znaków Unicode, w tym polskich znaków.
- Wykonywanie operacji XOR w WebAssembly.
- Automatyczne przetwarzanie tekstu podczas wpisywania.

## 🛠️ Technologie

- **C++** – implementacja algorytmu XOR.
- **WebAssembly (WASM)** – uruchamianie kodu C++ w przeglądarce.
- **Emscripten** – kompilacja C++ do WebAssembly.
- **HTML5** – struktura interfejsu.
- **CSS3** – stylowanie aplikacji.
- **JavaScript** – komunikacja z modułem WASM.

## 📂 Struktura projektu

```text
.
├── xor.cpp
├── xor.js
├── xor.wasm
└── index.html
```

## ⚙️ Kompilacja

Do kompilacji wymagany jest Emscripten SDK.

```bash
emcc xor.cpp -o xor.js \
-s WASM=1 \
-s EXPORTED_FUNCTIONS='["_xor_data","_malloc","_free"]' \
-s MODULARIZE=1 \
-s EXPORT_NAME='createXOR'
```

## 🚀 Uruchomienie

1. Sklonuj repozytorium:

```bash
git clone https://github.com/USERNAME/REPOSITORY.git
```

2. Przejdź do katalogu projektu:

```bash
cd REPOSITORY
```

3. Uruchom lokalny serwer HTTP:

```bash
python -m http.server 8000
```

4. Otwórz przeglądarkę pod adresem:

```text
http://localhost:8000
```

## 🔐 Jak działa szyfrowanie?

Aplikacja wykorzystuje operację XOR wykonywaną na bajtach tekstu.

W kodzie C++ zdefiniowany jest 32-bajtowy klucz:

```cpp
static const uint8_t secret[32] = {
'0','1','2','3','4','5','6','7',
'8','9','a','b','c','d','e','f',
'0','1','2','3','4','5','6','7',
'8','9','a','b','c','d','e','f'
};
```

Każdy bajt danych jest XOR-owany z odpowiednim bajtem klucza:

```cpp
data[i] ^= secret[i % 32];
```

Ta sama operacja służy do szyfrowania i deszyfrowania:

```text
A XOR B = C
C XOR B = A
```

### Format danych

Wynik szyfrowania jest kodowany w Base64 i otrzymuje prefiks:

```text
XOR1:
```

Aplikacja automatycznie rozpoznaje prefiks `XOR1:` i przeprowadza deszyfrowanie.

## ⚠️ Bezpieczeństwo

**Projekt ma charakter edukacyjny i demonstracyjny.**

Zastosowany algorytm XOR z powtarzanym, stałym kluczem nie zapewnia odpowiedniego bezpieczeństwa kryptograficznego.

- Klucz jest zapisany bezpośrednio w kodzie C++.
- Klucz jest powtarzany co 32 bajty.
- Kod WebAssembly można wyodrębnić i analizować.
- Base64 jest kodowaniem, a nie szyfrowaniem.
- Nie należy wykorzystywać tego rozwiązania do ochrony poufnych danych.

Do rzeczywistych zastosowań kryptograficznych zalecane jest wykorzystanie sprawdzonych algorytmów, np. AES-GCM.
