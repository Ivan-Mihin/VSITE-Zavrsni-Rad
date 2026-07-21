# Završni rad za VsiTe na temu "Predlošci dizajna"

## Opis projekta

Ovaj projekt predstavlja implementaciju popularne igre **Tetris** razvijenu za završni rad. Cilj projekta je pokazati u stvarnom programskom rješenju nekoliko važnijih predloška uz primjenu objektno orijentiranog programiranja. Projekt je razvijen u programskom jeziku C++, koristeći Microsoft Visual Studio 2022 i SFML 3.0.2 bibilioteku za grafički prikaz i interakciju s korisnikom. Isključivo podržava x64 konfiguraciju.

---

## Obrasci dizajna

U projektu je implementirano ukupno **pet obrazaca dizajna**:

### 1. Singleton

**Namjena:**
Osigurava da postoji samo jedna instanca određene klase tijekom izvođenja programa te omogućuje globalan pristup toj instanci.

**Primjena u projektu:**
Singleton je primjenjen na 3 mjesta.
1. Klasa Game. 
