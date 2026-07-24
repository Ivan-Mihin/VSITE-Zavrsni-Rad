# Završni rad za Veleučilište suvremenih informacijskih tehnologija na temu "Predlošci dizajna"

# Općenite informacije o projektu

## 1. Opis

Ovaj projekt predstavlja implementaciju popularne igre **Tetris** razvijenu za završni rad za Veleučilište suvremenih informacijskih tehnologija. Cilj projekta je pokazati u stvarnom programskom rješenju nekoliko važnijih predložaka uz primjenu objektno orijentiranog programiranja.

## 2. Igranje

Cilj igre je postaviti padajuće tetromino figure i ukloniti pune linije, čime se sakupljaju bodovi. Uklanjanje više linija odjednom ili uzastopno povećava broj bodova. Igra završava kada tetromino figure dosegnu crvenu liniju na vrhu ploče.

## 3. Kontrole

| Tipka | Akcija |
|---|---|
| Strelica lijevo ili slovo A| Pomicanje tetromino figure u lijevo |
| Strelica desno ili slovo D| Pomicanje tetromino figure u desno |
| Strelica gore ili slovo W| Rotacija tetromino figure |
| Strelica dolje ili slovo S| Brzo spuštanje tetromino figure prema dolje |
| Space | Nagli pad tetromino figure prema dolje|

## 4. Zahtjevi

Za izgradnju projekta i lokalno pokretanje potrebni su:

- Microsoft Windows operacijski sustav 
- Microsoft Visual Studio s instaliranim "Desktop development with C++" workload-om
- Podrška za C++17 standard
- SFML 3.0.2 biblioteka (već uključena u repozitorij)

---

# Upute za lokalnu izgradnju projekta

## 1. Odabir platforme i konfiguracije

Projekt podržava:

- platforme x64 i x86
- konfiguracije Debug i Release

U Visual Studio-u odaberite željenu kombinaciju platforme i konfiguracije prije izgradnje projekta.

## 2. Postavljanje SFML-a

SFML 3.0.2 biblioteka uključena je direktno u repozitorij. Struktura direktorija izgleda ovako:

```
SFML 3.0.2/
├── x64/
│   ├── include/
│   ├── lib/
│   └── bin/
│       ├── Debug/
│       └── Release/
└── x86/
    ├── include/
    ├── lib/
    └── bin/
        ├── Debug/
        └── Release/
```

Nakon kloniranja repozitorija nije potrebna dodatna instalacija SFML biblioteke. Sve potrebne datoteke SFML-a već su uključene unutar projekta. Nakon što se pokrene build solutiona, potrebne SFML `.dll` datoteke automatski će se kopirati u izlazni direktorij.

U slućaju da se `.dll` datoteke ne kopiraju ispravno, potrebno ih je ručno kopirati:

- iz mape `bin/` koja odgovara odabranoj platformi i konfiguraciji
- u izlazni direktorij gdje je izrađena `.exe` datoteka.

## 3. Resursi

Svi resursi aplikacije nalaze se u direktoriju `Assets`. Struktura direktorija izgleda ovako:

```
Assets/
├── Audio/
├── Fonts/
└── Textures/
```

Nakon što se pokrene build solutiona, svi Assets-i automatski će se kopirati u izlazni direktorij.

U slućaju da se Assets-i ne kopiraju ispravno, potrebno je ručno kopirati:

- mapu `Assets/`
- u izlazni direktorij gdje je izrađena `.exe` datoteka.

---

# Predlošci dizajna

U projektu su primijenjeni sljedeći predlošci dizajna:

- Obrazac jedinstvene instance (Singleton)
- Stanje (State)
- Metoda Tvornica (Factory Method)
- Naredba (Command)
- Promatrač (Observer)

## 1. Obrazac jedinstvene instance (Singleton)

Obrazac jedinstvene instance koristi se na tri mjesta:

- Game – središnji objekt aplikacije koji upravlja glavnom petljom igre i promjenom različitih stanja
- Assets – upravlja učitavanjem i pohranom resursa (teksture, fontovi, zvučni efekti i muzika)
- Audio – upravlja reprodukcijom glazbe i zvučnih efekata

## 2. Stanje (State)

Obrazac stanje koristi se za upravljanje različitim stanjima igre (glavni izbornik, igranje, završetak i izlazak iz igre). Svako stanje nasljeđuje apstraktnu klasu State koja definira zajedničko sučelje za rad sa stanjima.

## 3. Metoda Tvornica (Factory Method)

Obrazac metoda tvornica koristi se za stvaranje različitih vrsta tetromino figura, čime se logika njihove izrade odvaja od ostatka aplikacije.

## 4. Naredba (Command)

Obrazac naredba koristi se za enkapsulaciju korisničkih naredbi (pomicanje lijevo i desno, rotacija i nagli pad) u zasebne objekte. Na taj način se obrada korisničkog unosa odvaja od glavne logike igre.

## 5. Promatrač (Observer)

Obrazac promatrač koristi se za praćenje promjena vezanih uz bodove i kombo sustav. Kada dođe do promjene, povezani objekti se automatski ažuriraju bez potrebe za dodatnim povezivanjem s logikom igre.

---

# Struktura aplikacije

## Klasa Assets

Obrazac jedinstvene instance zadužen za učitavanje i pohranu svih resursa potrebnih za rad igre (tekstura, fontova, zvučnih efekata i muzike).

## Klasa Audio

Obrazac jedinstvene instance zadužen za upravljanje reprodukcijom zvučnih efekata i glazbe koristeći prethodno učitane i pohranjene resurse u instanci klase Assets.

## Klasa Game

Obrazac jedinstvene instance koji služi kao središnji objekt aplikacije. Upravlja glavnom petljom igre i promjenom različitih stanja. Tijekom inicijalizacije postavlja se stanje `StateMainMenu` kao zadano.

## Klasa State

Bazna klasa koja predstavlja sučelje za ostala stanja:

- `StateMainMenu`
- `StatePlaying`
- `StateGameOver`
- `StateExitGame`

Svako od tih stanja mora implementirati:

- handleInput() - metoda namjenjena za primanje i obradu korisničkog unosa
- update() - metoda namjenjena za obradu vremenski ovisnih promjena poput animacija ili padanja tetromino-a
- render() - metoda namjenjena za prikaz korisničkog sučelja na ekran

Također, da bi ostala što laganija, sva stanja sadrže svoju vlastitu pomoćnu klasu. Sama stanja zadužena su za upravljanje prijelazima između stanja i logiku specifičnu za njih, dok pomoćne klase preuzimaju obradu korisničkog sučelja, iscrtavanje sadržaja i ostale funkcionalnosti vezane uz pojedino stanje.

Pomoćne klase specifičnih stanja su:

- `StateMainMenu` -> `MainMenu`
- `StatePlaying` -> `Tetris`
- `StateGameOver` -> `GameOver`
- `StateExitGame` -> `ExitGame`

## Klasa Tetris

Pomoćna klasa stanja `StatePlaying`. Predstavlja glavnu klasu igre Tetris zaduženu za upravljanje logikom i tijekom igre. Povezuje sve ostale komponente (ploču, tetromino figure, bodovanje, korisnički unos i sučelje)

## Tetromino

Tetromino je klasa koja predstavlja opći model tetromino figure. Sadrži varijable i metode potrebne za rad figura u igri.

Konkretne tetromino figure su:

- `ShapeI`
- `ShapeJ`
- `ShapeL`
- `ShapeO`
- `ShapeS`
- `ShapeT`
- `ShapeZ`

One nasljeđuju `Tetromino` kao baznu klasu te u svojim konstruktorima definiraju vlastiti oblik, boju i raspored blokova za svaku rotaciju.

## Klasa Tetromino Factory

Klasa implementira obrazac metode tvornice za stvaranje tetromino figura. Statičkoj metodi createTetromino() prosljeđuje se vrijednost enumeracije `TetrominoShape`, na temelju koje se stvara odgovarajući objekt jedne od sedam dostupnih tetromino figura.

## Klasa Board

Predstavlja igraću ploču po kojoj se kreću tetromino figure te upravlja svim operacijama vezanim uz njihovo pozicioniranje, zaključavanje, uklanjanje popunjenih redova i provjeru stanja igre.

## Klasa ICommand

Definira apstraktno sučelje. Sadrži čisto virtualnu metodu execute() koju sve izvedene klase moraju implementirati.

## Klase Commands

Implementirane su 3 naredbe:

- `CommandMove`
- `CommandRotate`
- `CommandHardDrop`

Svaka od njih nasljeđuje sučelje ICommand i implementira metodu execute(). Funkcija handleInput() pri pritisku tipke pronalazi odgovarajuću naredbu u mapi key_bindings i izvršava njezinu metodu execute(), čime se obrada korisničkog unosa odvaja od logike igre.

## Klasa IObserver

Definira apstraktno sučelje. Sadrži čisto virtualnu metodu onNotify() koju sve izvedene klase moraju implementirati.

## Klasa Manager Score

Konkretni promatrač. Nasljeđuje sučelje IObserver i implementira metodu onNotify() koja ažurira rezultat i kombo te pruža metode za njihov dohvat.

## Subject

Implementira ulogu subjekta u obrascu promatrač. Održava popis registriranih promatrača te im šalje obavijesti o događajima pomoću metode notifyObservers(). Omogućuje dodavanje i uklanjanje promatrača putem metoda addObserver() i removeObserver().