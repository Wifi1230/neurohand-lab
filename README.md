# NeuroHand Lab

Projekt badawczo-prototypowy interfejsu neurotechnologicznego do sterowania wirtualną, a docelowo robotyczną ręką.

## Cel projektu

Zbudować system, który:

1. rejestruje aktywność mięśni za pomocą EMG,
2. przesyła dane do komputera przewodowo, a później przez BLE,
3. rozpoznaje proste gesty lub poziom napięcia mięśnia,
4. steruje wirtualną ręką,
5. docelowo może sterować prostym mechanizmem robotycznej ręki,
6. w dalszym etapie może zostać rozszerzony o EEG/BCI.

Projekt jest prototypem edukacyjnym i nie jest urządzeniem medycznym.

## Aktualny sprzęt

| Element | Zastosowanie | Status |
|---|---|---|
| DFRobot Gravity SEN0240 | Pomiar sygnału EMG | Zamówiony |
| Waveshare ESP32-S3-DEV-KIT-N8R8 | Odczyt EMG, przetwarzanie i BLE | Zamówiony |
| Breadboard 830 pól | Tymczasowe prototypowanie połączeń | Zamówiony |
| Przewody Dupont | Połączenia ESP32, czujnika i LED | Zamówione |
| Kabel USB-A → USB-C | Programowanie ESP32 i testy z komputerem | Zamówiony |
| Diody LED 5 mm | Sygnalizacja wykrycia aktywności mięśnia | Zamówione |
| Rezystory 330 Ω | Ograniczenie prądu diody LED | Zamówione |

Serwomechanizmy i mechanika ręki zostaną dodane dopiero po uruchomieniu i przetestowaniu części EMG.

## Plan rozwoju

### Etap 1 — uruchomienie elektroniki

- [ ] Zaprogramować ESP32-S3.
- [ ] Potwierdzić komunikację USB z komputerem.
- [ ] Podłączyć diodę LED przez rezystor 330 Ω.
- [ ] Potwierdzić sterowanie diodą.

### Etap 2 — pomiar EMG

- [ ] Podłączyć SEN0240 do ESP32-S3.
- [ ] Odczytać sygnał analogowy.
- [ ] Wyświetlić wartości i wykres sygnału.
- [ ] Sprawdzić poziom spoczynkowy, zakłócenia i reakcję na napięcie mięśnia.
- [ ] Opisać bezpieczne rozmieszczenie elektrod.

### Etap 3 — wirtualna ręka

- [ ] Przesyłać dane EMG do aplikacji na komputerze.
- [ ] Zaimplementować sterowanie otwieraniem i zamykaniem dłoni.
- [ ] Dodać kalibrację dla użytkownika.
- [ ] Zmierzyć opóźnienie i stabilność działania.

### Etap 4 — komunikacja bezprzewodowa

- [ ] Przesyłać dane EMG przez BLE.
- [ ] Odbierać dane na komputerze lub telefonie.
- [ ] Przetestować działanie zasilane z powerbanku.

### Etap 5 — rozpoznawanie gestów

- [ ] Zebrać oznaczone próbki danych.
- [ ] Wstępnie filtrować i normalizować sygnał.
- [ ] Rozpoznać co najmniej dwa gesty.
- [ ] Zmierzyć skuteczność, opóźnienie i powtarzalność.

### Etap 6 — mechanizm robotycznej ręki

- [ ] Zaprojektować lub wybrać prosty chwytak.
- [ ] Dodać serwomechanizm i osobne zasilanie.
- [ ] Ograniczyć zakres ruchu i siłę.
- [ ] Sterować mechanizmem na podstawie sygnału z wirtualnej ręki.

### Etap 7 — możliwe rozszerzenie EEG/BCI

EEG będzie osobnym torem pomiarowym. Elektrody EEG nie mogą być podłączone bezpośrednio do GPIO ESP32 — potrzebny jest specjalizowany, niskoszumowy wzmacniacz i przetwornik ADC. ESP32 może później odbierać i przetwarzać dane z takiego modułu.

## Pierwsze połączenie

Połączenie SEN0240 z ESP32-S3:

```text
SEN0240 VCC  → 3V3
SEN0240 GND  → GND
SEN0240 SIG  → wejście ADC, np. GPIO1
```

LED:

```text
GPIO4 → rezystor 330 Ω → długa nóżka LED
krótka nóżka LED → GND
```

Przed podłączeniem należy sprawdzić oznaczenia pinów na konkretnych płytkach. Nie należy kierować się wyłącznie kolorami przewodów.

## Dokumentacja eksperymentów

Każdy eksperyment powinien zawierać:

- datę i wersję kodu,
- cel testu,
- schemat lub opis połączeń,
- użyte ustawienia,
- wynik i zebrane dane,
- napotkane problemy,
- wnioski oraz następny krok.

## Bezpieczeństwo

- Elektrody stosować wyłącznie na nieuszkodzonej skórze.
- Nie umieszczać elektrod na klatce piersiowej ani szyi.
- Pierwsze testy z elektrodami wykonywać przy zasilaniu bateryjnym.
- Nie podłączać serw do zasilania ESP32.
- Projekt nie jest certyfikowanym urządzeniem medycznym i nie służy do diagnostyki ani leczenia.

## Status

**Status:** przygotowanie pierwszego prototypu EMG  
**Następny cel:** uruchomić ESP32-S3, LED i odczyt sygnału z SEN0240.
