# Kreditkartenvalidierung mit Luhn's Algorithmus

Dieses Programm validiert Kreditkartennummern mithilfe von Luhn's Algorithmus und erkennt Kartentypen wie AMEX, VISA und MASTERCARD.

## Funktionsweise

Das Programm führt folgende Schritte aus:
1. Der Benutzer gibt eine Kreditkartennummer ein.
2. Luhn's Algorithmus überprüft die Nummer, indem jede zweite Ziffer verdoppelt und die Quersumme gebildet wird.
3. Das Programm validiert die Prüfziffer und erkennt den Kartentyp anhand der Länge und des Präfixes.
4. Der Kartentyp wird ausgegeben, oder es wird eine Fehlermeldung angezeigt, wenn die Nummer ungültig ist.

## Unterstützte Kreditkarten

- **American Express (AMEX):** 15 Ziffern, beginnt mit "34" oder "37"
- **MasterCard:** 16 Ziffern, beginnt mit "51", "52", "53", "54", "55"
- **Visa:** 13 oder 16 Ziffern, beginnt mit "4"

## Beispielausgabe
```bash
Dieses Programm validiert Kreditkartennummern.
Unterstützte Karten: AMEX, VISA und MASTERCARD.
Bitte geben Sie eine Kreditkartennummer zur Validierung ein.
Number: 4111111111111111
VISA
```

## Technologie

- **Programmiersprache:** C
- **Bibliotheken:** `<stdio.h>`, `<stdbool.h>`, `<string.h>`

## Erweiterbarkeit

Das Programm ist einfach erweiterbar, um neue Kreditkartentypen oder zusätzliche Validierungsregeln zu unterstützen. Um eine neue Kreditkarte hinzuzufügen, passe die Präfix- und Längenüberprüfung in der Funktion `validate_card()` an.

## Lizenz

Dieses Projekt ist unter der MIT-Lizenz lizenziert. Weitere Informationen findest du in der [LICENSE](LICENSE)-Datei.

