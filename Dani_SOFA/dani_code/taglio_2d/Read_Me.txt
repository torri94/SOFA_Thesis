Viene provato il taglio 2d, ma senza successo.
Il taglio dev'essere fatto da mouse, tramite MAIUSC + Middle_button (Tasto rotellina mouse).
Ma se si effettua il taglio, al primo contatto tra modello e phantom i programma crashano. 
Questo perchè il modello viene modificato nella fisica e nei vincoli (Topologia). 
Il phantom quando calcola la collisione, si ricalcola tutti i vincoli.
Ma le due parti non sono attualmente gestite da sofa.

File 1 contiene solo il modello
File 2 contiene modello e Phantom, ma senza interazione
File 3 contiene modello e Phantom con interazione ma solver lento
File 4 contiene modello e Phantom con interazione e solver rapido