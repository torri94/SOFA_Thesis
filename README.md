# SOFA_Thesis
Tutto il codice si trova in Dani_SOFA.

Al suo interno c'è:

**Plugin**
C'è un nuovo plugin da inserire chiamato *dani*, con il relativo CMake. Il CMake non è da copiare, bisogna modificare quello già presente nella cartella plugin aggiungendo "dani". Per specifiche rifarsi a https://www.sofa-framework.org/community/doc/programming-with-sofa/create-your-plugin/


**dani_code**

Sono i tutte le varie scene da me create:
modello_eterogeneo è la cartella contenente i 50 trials della mia tesi (i file sono 100 perchè per ogni scena ho definito anche la sua visualizzazione)
Prove_pre_EEG contiene tutte le configurazioni fatte per testare i parametri per il test (Valori fisici della pelle, diametro nodulo, durezza nodulo, profondità ecc..)
eliminazione_mesh non dovrebbe funzionare perchè necessità del plugin Carving (presente in SOFA)
IMPORTANTE: prima di far runnare le scene è importante inserire le mesh nuove all'interno di SOFA


**mesh**

Contiene le mesh da me prodotte, vanno salvate dentro la cartella  C:\--\Sofa\src\share\mesh
(estrarre dalla cartella e salvare insieme alle altre)


**Componenti**

*GeomagicDriver.cpp* e *GeomagicDriver.h* va sostituita all'interno del plugin Geomagic ( C:\--\Sofa\src\applications\plugins\Geomagic\src\Geomagic) 
In questa componente ho implementato l'invio del segnale quando viene schiacciato un qualsiasi tasto del Phantom Omni
*EvalPointsDistance.* vanno sovrascritte in C:\--\Sofa\src\modules\SofaValidation\src\SofaValidation
è la creazione del segnale di avvio della simulazione e stampano i tempi in un file
*Monitor.* vanno sovrascritti in C:\--\Sofa\src\modules\SofaValidation\src\SofaValidation
Ho aggiunto delle nuove informazioni nel file stampati
*ExtraMonitor.* vanno sovrascritti in C:\--\Sofa\src\modules\SofaValidation\src\SofaValidation
Ho aggiunto delle nuove informazioni nel file stampati


**IMPORTANTISSIMO**
La simulazione della mia tesi prevede scrivere le informazioni della simualazione in file di testo .txt
Per far questo dev'essere creata una cartella behaviors in **C:\--\Sofa\build\bin\Release** contenente 50 cartelle vuote. I nomi delle cartelle sono solo numeri da 1 a 50.
Copiare cartella behaviors in **C:\--\Sofa\build\bin\Release**
