# 🤖 ORGANIZED

## 🧭 DESCRIPTION DU PROJET

L'objectif de ce projet est de développer un système en C pour stocker et trier différents types de matériaux de laboratoire (outils, composants électroniques, documents)
-> via une interface en ligne de commande -> shell.

---

## 🗓️ DATES

📅 **Du 22/11/2025 à 08h42 au 12/12/2025 à 19h42**

---

## 🚀 UTILISATION

### - Options :

```bash
./organized

Workshop >> add WIRE usb
WIRE n°0 "usb" added.
Workshop >> sort TYPE -r
Workshop >> disp
...
Workshop >> exit
```

#### - Le programme peut également traiter des fichiers de commandes via un pipe pour les tests automatisés :

```bash
$ cat example_test | ./organized
```


### 🛠️ COMMANDES à implémenter :

[+] add : ajoute un ou plusieurs nouveaux matériaux à l'atelier. Les matériaux sont ajoutés dans la liste chaînée en ordre inverse d'ajout.
(EX: add ACTUATOR button, DEVICE recorder)
[-] del : supprime un ou plusieurs matériaux de l'atelier en utilisant leur ID unique.
(EX: del 1, 2)
[~] disp : affiche le contenu actuel de l'atelier (les matériaux stockés).
(EX: disp)
[\] sort : trie tous les matériaux présents selon un ou plusieurs tags.
(EX: sort NAME ID -r)


#### ⚙️ Matériaux (Hardwares) :
  - ACTUATORS
  - DEVICES
  - PROCESSORS
  - SENSORS
  - WIRES
Chaque matérial doit avoir un TYPE, un NOM et un ID unique (commençant à 0 et incrémenté).

#### 🚩 Tags de tri :
- TYPE
- NAME
- ID
Le flag -r peut être ajouté après un tag pour effectuer un tri en ordre inverse (décroissant). Le tri peut utiliser plusieurs tags (tri secondaire).


### 🧪 EXEMPLES D'UTILISATION :

```bash
$ ./organized (-> add/del/disp/sort functions)
Workshop >> add WIRE usb, ACTUATOR button, DEVICE recorder, WIRE d
WIRE n°0 - "usb" added.
ACTUATOR n°1 - "button" added.
DEVICE n°2 - "recorder" added.
WIRE n°3 - "d" added.
Workshop >> del 1, 2
ACTUATOR n°1 - "button" deleted.
DEVICE n°2 - "recorder" deleted.
Workshop >> disp
WIRE n°3 - "d"
WIRE n°0 - "usb"
Workshop >> add ACTUATOR button1
ACTUATOR n°4 - "button1" added.
Workshop >> add DEVICE screen
DEVICE n°5 - "screen" added.
Workshop >> disp
DEVICE n°5 - "screen"
ACTUATOR n°4 - "button1"
WIRE n°3 - "d"
WIRE n°0 - "usb"
Workshop >> sort NAME -r
Workshop >> disp
WIRE n°0 - "usb"
DEVICE n°5 - "screen"
WIRE n°3 - "d"
ACTUATOR n°4 - "button1"
Workshop >> exit
```

## 📁 FICHIERS && STRUCTURE DU PROJET :

###  - Projet dispersé en plusieurs sous-dossiers et fichiers pour avoir plus de clarté sur celui-ci.

```bash
├── include
│   ├── my.h
│   └── shell.h
├── lib
│   ├── libmy.a
│   ├── libshell.a
│   └── my
├── Makefile
├── organized
└── src
    ├── add_node
    │   ├── add_node.c
    │   └── print_add.c
    ├── delete_node
    │   ├── delete.c
    │   ├── free_delete.c
    │   └── print_delete.c
    ├── display_node
    │   ├── display_node.c
    │   └── print_disp.c
    ├── free_list
    │   └── free_list.c
    ├── main.c
    ├── nodes
    │   └── create_node.c
    └── sort_node
        ├── clean_sort.c
        ├── comp_elements.c
        ├── crits.c
        ├── exec_sort.c
        ├── get_lists_array.c
        ├── quick_sort.c
        └── sort.c
```
