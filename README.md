# Vertex Cover problem

Implementace aproximačních algoritmů pro problém minimálního pokrytí vrcholů.

### Autoři
#### Vladimír Jeřábek
#### Jan Kohút


### Překlad 

```
mkdir build
cd build 
cmake ..
make
```

Vytvoří program vc.

### Spuštění

```
./vc -g cesta_k_souboru_grafu
     -m metoda [GIC|MDG|ME|DUMMY|BT]
     -i pocet_iteraci_experimentu (kolikrát se spustí algoritmus nad grafem)
     -p remove_pendant (default false, smazání pendant vrcholů)
     -r remove_redundant (default false, smazání redundantních uzlů z pokrytí)
     
./vc -g ../test/graphs/graph_V10_D0.txt  -m ME -i 10 -p -r
```

Výstup se uloží do cesta_k_souboru_grafu.out, první hodnota je průměrná doba 
běhu algoritmu přes všechny iterace, druhá hodnota je průměrná velikost pokrytí.



#### Skripty pro experimenty:

```
cd scripts/
```

Zde se nachází skripty použité pro experimenty.
Jednotlivé skripty mají popsané své použití.

#### Data pro experimenty:
[Odkaz na Google Disk](https://drive.google.com/drive/folders/1QymWQCwExOFlnKIJnHOJLz4HCFZkdgE_?usp=sharing)

