#Préparer son PC  
**Ajouter l'utilisateur au groupe dialout** 
<br>
<br>
  `$ sudo vi /etc/group`    
  <br>
  Editer /etc/group :
>dialout:x:20:nom de l'utilisateur


#Installation de OpenCv

**Installer les dépendances**    
Ces commandes sont pour Debian/Ubuntu    
`$ sudo apt-get install build-essential`  
`$ sudo apt-get install libavformat-dev`  
`$ sudo apt-get install ffmpeg`  
`$ sudo apt-get install cmake`

On télécharge les sources de OpenCV sur sourceforge  
`$ wget http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/2.4.0/OpenCV-2.4.0.tar.bz2/download` 

On désarchive le dossier   
`$ tar -xf OpenCV-2.4.0.tar.bz2`   

On crée un dossier build et on va dedans  
`$ mkdir opencv.build`  
`$ cd opencv.build`  

Et l’on installe  
`$ cmake ../OpenCV-2.4.0`   
`$ make `   
`$ sudo make install`   
`$ sudo ldconfig`  

En cas de problème pendant l'installation de OpenCV vous pouvez consulter :
[http://opencv.willowgarage.com/wiki/InstallGuide](http://opencv.willowgarage.com/wiki/InstallGuide)


#Télécharger et compiler

Récupérer les sources  
`$ wget https://github.com/ludovicl/Examesure-Linux/zipball/master/Examesure-Linux.zip` 

Extraire les sources  
`$ unzip Examesure-Linux.zip`

On va dans le répertoire source  
`$ cd ludovicl-Examesure-Linux*/src`

On compile  
`$ qmake`  
`$ make` 

En cas de problèmes pendant la compilation  
 `$ make clean`

On peut exécuter l'exécutable  
`./examesure`

#Installation du logiciel de developpement :

**Télécharger Qt SDK**

On récupére le fichier d'installion 32 bits
`$ wget http://www.developer.nokia.com/dp?uri=http%3A%2F%2Fsw.nokia.com%2Fid%2Ff33d3d5a-d847-4b30-8637-9a6b33f83ed2%2FQt_SDK_Lin32_online` 

On donne les droits d'execution :  
`$ chmod u+x Qt_SDK_Lin32_online_v1_2_en.run`  

On éxécute :  
`$ ./Qt_SDK_Lin32_online_v1_2_en.run` 

En ca se probléme d'affichage :   
`$ ./Qt_SDK_Lin32_online_v1_2_en.run -style cleanlooks`



