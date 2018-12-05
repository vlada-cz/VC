# VC

Implementace aproximačních algoritmů pro problém minimálního pokrytí vrcholů.

### Překlad 

```
mkdir build
cd build 
cmake ..
make
```

Vytvoří program vc

## Spuštění

```
./vc -g cesta_k_souboru_grafu
     -m metoda [GIC|MDG|ME|DUMMY|BT]
     -i pocet_iteraci_experimentu (kolikrát se spustí algoritmus nad grafem)
     -p remove_pendant (default false, smazání pendant vrcholů)
     -r remove_redundant (default false, smazání redundantních uzlů z pokrytí)
```

Výstup se uloží do cesta_k_souboru_grafu.out, první hodnota je průměrná doba 
běhu algoritmu přes všechny iterace, druhá hodnota je průměrná velikost pokrytí.

