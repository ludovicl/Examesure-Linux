#Documentation technique programme GNU/Linux pour four Fluid 200
##Utilisation des classes

### Classe Camera
  
`void connecter(int idcam);`  

Cette méthode sert à connecter et afficher la webcam
L'argument idcam correspond à l'emplacement de la webcam, il peut être de -1, 0, 1, 2,...  
-1 pour la première webcam de disponible  
0 pour la webcam définie en /dev/video0  
1 pour la webcam définie en /dev/video1  
etc.  


### Classe Etalonnage

`bool testStabilite(vector<float>tabTempRecup);`  

L'argument tabTempRecup définit les 240 températures de la sonde de référence et permet de vérifier la stabilité.  
Cette méthode retourne true si la stabilité est correcte, false si elle est incorrecte


`void remplir_tabTemp();`  

Cette méthode permet de remplir le vector tabTemp en fonction des valeurs entrées dans l'ihm.

### Classe Four

`void definirTemp(QString cons);`  

Cette méthode permet d'envoyer une consigne au four, l'argument cons est la consigne en degrés Celsius.


### Classe Rs232
Cette classe est un singleton

**Constructeur :**  
Le constructeur établit la connexion avec la liaison Rs232 en utilisant open();  

`void ecrire(QString data, int id_tty );`  

ecrire permet de modifier la consigne du four.  
L'argument data est la consigne à envoyer et id_tty est la valeur retournée lors de l'ouverture de la voie série avec open();

`QString recevoir(QString data , int id_tty );`  

Cette méthode retourne un état du four.
L'argument data est le type de lecture d'état que l'on désire (ex : 0 pour lire la consigne). id_tty est la valeur retournée lors de l'ouverture de la voie série avec open();


### Classe Sonde
**Constructeur :**  
Ce constructeur définit le type de sonde de l'objet (interne, externe ou référence)

`QString acquerirTemp();`

Cette méthode retourne une température en fonction du  type de sonde rentrée en paramétre.



