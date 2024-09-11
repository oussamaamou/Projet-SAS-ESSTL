#include<stdio.h>
#include<string.h>


int type;
int NumeroUnique;
char Nom[20];
char Prenom[20];
float NoteGenerale;
char Departement[30];
int i,j;
int NbrAjout;
int Mdfction;
int nombretotale = 0;





typedef struct{
    int Jour;
    int Mois;
    int Annee;

}DateNaissance;



typedef struct{
    int NumeroUnique;
    char Nom[20];
    char Prenom[20];
    float NoteGenerale;
    char Departement[30];
    DateNaissance DateNssce;

}Etudiant;

Etudiant Etudiants[600];
DateNaissance Dates[600];

void AfficherNbrTtle(){
    printf("Voici le Nombre Total des Etudiants de l'Universite :");
}

void AfficherTousEtudiant(){
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Voici la liste de tous les Etudiants de l'Universite :");
    printf("\n---------------------------------------------------------------------------------------\n");
    if(nombretotale == 0){
        
        printf("\n---------------------------------------------------------------------------------------\n");
        printf("Il n'existe aucun Etudiant pour l'instant.");
        printf("\n---------------------------------------------------------------------------------------\n");
        return ;
    }
    for(i=0;i<nombretotale;i++){
        printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
        printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
        printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Departement);
        printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
        printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Dates[i].Jour,Dates[i].Mois,Dates[i].Annee);
        printf("\n---------------------------------------------------------------------------------------\n");
        printf("\n---------------------------------------------------------------------------------------\n");
        

    }
    
}

void SupprimerUnEtudiant(){
    printf("Vous voulez vraiment supprimer les informations de cet Etudiant :\n");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("[1]-Confirmer la suppression : \n");
    printf("[2]-Retourner au Menu Principale : \n");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("Entrer votre choix :");
    scanf("%d",&Mdfction);
    printf("\n---------------------------------------------------------------------------------------\n"); 
    switch(Mdfction){
        case 1:
            for(i=0;i<nombretotale;i++)
                for(j=i;j<nombretotale - 1;j++)
                    Etudiants[j] = Etudiants[j + 1];      

            nombretotale --;
            printf("---------------------------------------------------------------------------------------\n");
            printf("Les informations se sont supprimes avec succes.\n");
            printf("---------------------------------------------------------------------------------------\n");    
        break;
            

        
        case 2:
            printf("Retour au Menu Principale.");
            return ;

        default :
            printf("Choix invalide!! Entrer un autre choix :");
        break;
    }



}

void TypeModification(){
    
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("Quelles informations voulez-vous Modifier :");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("\t[1]-Nom : \n \t[2]-Prenom : \n \t[3]-Date de Naissance : \n \t[4]-Departement \n \t[5]-Note Generale : \n \t[6]-Toutes les Informations : \n");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("\tEntrer votre Choix :");
    scanf("%d",&Mdfction);
    switch(Mdfction){
        
        case 1:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Nom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[nombretotale].Nom);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tLe Nom est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n");                

        break;   
        
        case 2:

            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Prenom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[nombretotale].Prenom);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tLe Prenom est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
      
        break;   
        
        case 3:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer la nouvelle Date de Naissance :\n");
            printf("\t Entrer le nouveau Jour :");
            scanf("%d",&Dates[nombretotale].Jour);
            printf("\t Entrer le nouveau Mois :");
            scanf("%d",&Dates[nombretotale].Mois);
            printf("\t Entrer la nouvelle Annee :");
            scanf("%d",&Dates[nombretotale].Annee);
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tLa Date de Naissance est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
            break;

        case 4:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer le nouveau Departement :\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t[1]-Mathematique et Informatique : \n \t[2]-Physique : \n \t[3]-Chimie : \n \t[4]-Biologie \n \t[5]-Sciences de la Terre : \n \t[6]-Sciences Economiques et de Gestion : \n \t[7]-Droit : \n \t[8]-Geographie : \n \t[9]-Anglais :\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t Choisissez un Departement :");
            scanf("%d",&type);
            getchar();
            switch(type){
                case 1:
                    strcpy(Etudiants[nombretotale].Departement,"Mathematique et Informatique\n");
                    break;
                
                case 2:
                    strcpy(Etudiants[nombretotale].Departement,"Physique\n");
                    break;
                
                case 3:
                    strcpy(Etudiants[nombretotale].Departement,"Chimie\n");
                    break;
                
                case 4:
                    strcpy(Etudiants[nombretotale].Departement,"Biologie\n");
                    break;
                
                case 5:
                    strcpy(Etudiants[nombretotale].Departement,"Sciences de la Terre\n");
                    break;
                
                case 6:
                    strcpy(Etudiants[nombretotale].Departement,"Sciences Economiques et de Gestion\n");
                    break;
                
                case 7:
                    strcpy(Etudiants[nombretotale].Departement,"Droit\n");
                    break;
                
                case 8:
                    strcpy(Etudiants[nombretotale].Departement,"Geographie\n");
                    break;
            
                case 9:
                    strcpy(Etudiants[nombretotale].Departement,"Anglais\n");
                    break;
                
                default :
                    printf("Choix invalide!! Entrer un nouveau choix :");
                    break;
            }
            printf("---------------------------------------------------------------------------------------\n");
            printf("\tLe Departement est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n");
            break;

        case 5:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer la Nouvelle Note Generale :");
            scanf("%f",&Etudiants[nombretotale].NoteGenerale);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tLa Note Generale est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
            break;

        case 6:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Nom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[nombretotale].Nom);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Prenom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[nombretotale].Prenom);
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer la nouvelle Date de Naissance :\n");
            printf("\t Entrer le nouveau Jour :");
            scanf("%d",&Dates[nombretotale].Jour);
            printf("\t Entrer le nouveau Mois :");
            scanf("%d",&Dates[nombretotale].Mois);
            printf("\t Entrer la nouvelle Annee :");
            scanf("%d",&Dates[nombretotale].Annee);
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer le nouveau Departement :\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t[1]-Mathematique et Informatique : \n \t[2]-Physique : \n \t[3]-Chimie : \n \t[4]-Biologie \n \t[5]-Sciences de la Terre : \n \t[6]-Sciences Economiques et de Gestion : \n \t[7]-Droit : \n \t[8]-Geographie : \n \t[9]-Anglais :\n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t Choisissez un Departement :");
            scanf("%d",&type);
            getchar();
            switch(type){
                case 1:
                    strcpy(Etudiants[nombretotale].Departement,"Mathematique et Informatique\n");
                    break;
                
                case 2:
                    strcpy(Etudiants[nombretotale].Departement,"Physique\n");
                    break;
                
                case 3:
                    strcpy(Etudiants[nombretotale].Departement,"Chimie\n");
                    break;
                
                case 4:
                    strcpy(Etudiants[nombretotale].Departement,"Biologie\n");
                    break;
                
                case 5:
                    strcpy(Etudiants[nombretotale].Departement,"Sciences de la Terre\n");
                    break;
                
                case 6:
                    strcpy(Etudiants[nombretotale].Departement,"Sciences Economiques et de Gestion\n");
                    break;
                
                case 7:
                    strcpy(Etudiants[nombretotale].Departement,"Droit\n");
                    break;
                
                case 8:
                    strcpy(Etudiants[nombretotale].Departement,"Geographie\n");
                    break;
            
                case 9:
                    strcpy(Etudiants[nombretotale].Departement,"Anglais\n");
                    break;
                
                default :
                    printf("Choix invalide!! Entrer un nouveau choix :");
                    break;
            }
            printf("\t Veuillez entrer la Nouvelle Note Generale :");
            scanf("%f",&Etudiants[nombretotale].NoteGenerale);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("Les informations se sont modifiees avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
            break;

        default :
            printf("Choix invalide!! Entrer un nouveau choix :");
            break;

    }


}

void AjoutSimple(){
    int info = 0,ph = 0,ch = 0,bg = 0,svt = 0,eco = 0,dr = 0,gh = 0,ag = 0;

    printf("\t Veuillez entrer le Nom de l'etudiant :");
    scanf(" %[^\n]s",&Etudiants[nombretotale].Nom);
    
    printf("\t Veuillez entrer le Prenom de l'etudiant :");
    scanf(" %[^\n]s",&Etudiants[nombretotale].Prenom);
    
    printf("\t Veuillez entrer la Note Generale de l'etudiant :");
    scanf("%f",&Etudiants[nombretotale].NoteGenerale);
   
    printf("\t Veuillez entrer la Date de Naissance de l'Etudiant:\n");
    printf("\t Entrer le Jour :");
    scanf("%d",&Dates[nombretotale].Jour);
    printf("\t Entrer le Mois :");
    scanf("%d",&Dates[nombretotale].Mois);
    printf("\t Entrer l'Annee :");
    scanf("%d",&Dates[nombretotale].Annee);
    
    printf(" Veuillez entrer le Departement de l'etudiant :");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t[1]-Mathematique et Informatique : \n \t[2]-Physique : \n \t[3]-Chimie : \n \t[4]-Biologie \n \t[5]-Sciences de la Terre : \n \t[6]-Sciences Economiques et de Gestion : \n \t[7]-Droit : \n \t[8]-Geographie : \n \t[9]-Anglais :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&type);
    getchar();
    switch(type){
        case 1:
            strcpy(Etudiants[nombretotale].Departement,"Mathematique et Informatique\n");
            info ++;
            break;
        
        case 2:
            strcpy(Etudiants[nombretotale].Departement,"Physique\n");
            ph ++;
            break;
        
        case 3:
            strcpy(Etudiants[nombretotale].Departement,"Chimie\n");
            ch ++;
            break;
        
        case 4:
            strcpy(Etudiants[nombretotale].Departement,"Biologie\n");
            bg ++;
            break;
        
        case 5:
            strcpy(Etudiants[nombretotale].Departement,"Sciences de la Terre\n");
            svt ++;
            break;
        
        case 6:
            strcpy(Etudiants[nombretotale].Departement,"Sciences Economiques et de Gestion\n");
            eco ++;
            break;
        
        case 7:
            strcpy(Etudiants[nombretotale].Departement,"Droit\n");
            dr ++;
            break;
        
        case 8:
            strcpy(Etudiants[nombretotale].Departement,"Geographie\n");
            gh ++;
            break;
       
        case 9:
            strcpy(Etudiants[nombretotale].Departement,"Anglais\n");
            ag ++;
            break;
        
        default :
            printf("Choix invalide!! Entrer un nouveau choix :");
            break;
    }
    Etudiants[nombretotale].NumeroUnique = nombretotale + 1;
    nombretotale ++;
    printf("---------------------------------------------------------------------------------------\n");   
    printf("Les informations de l'Etudiant sont ajoutees avec succes.\n");
    printf("---------------------------------------------------------------------------------------\n");

}

void AjoutMultiple(){
    int info = 0,ph = 0,ch = 0,bg = 0,svt = 0,eco = 0,dr = 0,gh = 0,ag = 0;

    printf("---------------------------------------------------------------------------------------\n");
    printf("Veuillez saisir le nombre des Etudiants que vous voulez Ajouter :");
    scanf("%d",&NbrAjout);
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0;i<NbrAjout;i++){
        printf("\t Veuillez entrer le Nom de l'etudiant :");
    scanf(" %[^\n]s",&Etudiants[i].Nom);
    
    printf("\t Veuillez entrer le Prenom de l'etudiant :");
    scanf(" %[^\n]s",&Etudiants[i].Prenom);
    
    printf("\t Veuillez entrer la Note Generale de l'etudiant :");
    scanf("%f",&Etudiants[i].NoteGenerale);
   
    printf("\t Veuillez entrer la Date de Naissance de l'Etudiant:\n");
    printf("\t Entrer le Jour :");
    scanf("%d",&Dates[i].Jour);
    printf("\t Entrer le Mois :");
    scanf("%d",&Dates[i].Mois);
    printf("\t Entrer l'Annee :");
    scanf("%d",&Dates[i].Annee);
    
    printf(" Veuillez entrer le Departement de l'etudiant :");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t[1]-Mathematique et Informatique : \n \t[2]-Physique : \n \t[3]-Chimie : \n \t[4]-Biologie \n \t[5]-Sciences de la Terre : \n \t[6]-Sciences Economiques et de Gestion : \n \t[7]-Droit : \n \t[8]-Geographie : \n \t[9]-Anglais :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&type);
    getchar();
    switch(type){
        
        case 1:
            strcpy(Etudiants[i].Departement,"Mathematique et Informatique\n");
            info ++;
            break;
        
        case 2:
            strcpy(Etudiants[i].Departement,"Physique\n");
            ph ++;
            break;
        
        case 3:
            strcpy(Etudiants[i].Departement,"Chimie\n");
            ch ++;
            break;
        
        case 4:
            strcpy(Etudiants[i].Departement,"Biologie\n");
            bg ++;
            break;
        
        case 5:
            strcpy(Etudiants[i].Departement,"Sciences de la Terre\n");
            svt ++;
            break;
        
        case 6:
            strcpy(Etudiants[i].Departement,"Sciences Economiques et de Gestion\n");
            eco ++;
            break;
        
        case 7:
            strcpy(Etudiants[i].Departement,"Droit\n");
            dr ++;
            break;
        
        case 8:
            strcpy(Etudiants[i].Departement,"Geographie\n");
            gh ++;
            break;
        
        case 9:
            strcpy(Etudiants[i].Departement,"Anglais\n");
            ag ++;
            break;
        
        default :
            printf("Choix invalide!! Entrer un nouveau choix :");
            break;
    }
    Etudiants[i].NumeroUnique = nombretotale + 1;
    nombretotale ++;
    printf("---------------------------------------------------------------------------------------\n");
    printf("Les informations de l'Etudiant se sont ajoutees avec succes.\n");
    printf("---------------------------------------------------------------------------------------\n");
    }
    printf("Les informations de tous ces Etudiants se sont ajoutes avec succes.\n");
}

void AjouterUnEtudiant(){
   
    printf("\t Quel type d'Ajout vous Voulez :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t [1] Un Ajout Simple :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t [2] Un Ajout Multiple :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez votre type d'Ajout :");
    scanf("%d",&type);
    printf("---------------------------------------------------------------------------------------\n");
    getchar();
    
    switch(type){
        case 1:
            AjoutSimple();
            break;

        case 2:
            AjoutMultiple();
            break;

        default :
            printf("Choix invalide!! Entrer un nouveau choix :");
            break;    
            
    }

}

void ModifierUnEtudiant(){
    printf("Veuillez entrer le Numero Unique de l'Etudiant :");
    scanf("%d",&NumeroUnique);
    for(i=0;i<nombretotale;i++){
        if(Etudiants[i].NumeroUnique == NumeroUnique){
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("Choisissez une Option : \n");
            printf("\t[1]-Modifier les informations de cet Etudiant : \n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t[2]-Supprimer les informations de cet Etudiant : \n");
            printf("---------------------------------------------------------------------------------------\n");
            printf("\tEntrer votre choix : ");
            scanf("%d",&Mdfction);
            switch(Mdfction){
                case 1:
                    TypeModification();
                    break;

                case 2:
                    SupprimerUnEtudiant();
                    break;

                default :
                    printf("Choix invalide!! Entrer un nouveau choix :");
                    break;        
            }



        }       
    }
   
    printf("Le Numero Unique de l'Etudiant est incorrect !!!\n");
    
        

}

void MoynnDprtment(){
    int S = 0;
    int M = 0;
    int info,ph,ch,bg,svt,eco,dr,gh,ag;

    printf("\t Voici les Departement de l'Universite :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t[1]-Mathematique et Informatique : \n \t[2]-Physique : \n \t[3]-Chimie : \n \t[4]-Biologie \n \t[5]-Sciences de la Terre : \n \t[6]-Sciences Economiques et de Gestion : \n \t[7]-Droit : \n \t[8]-Geographie : \n \t[9]-Anglais :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&type);
    getchar();
    switch(type){
        
        case 1:
            for(i=0;i<nombretotale;i++){
                if(strcmp(Etudiants[i].Departement,"Mathematique et Informatique") == 0){
                   S += Etudiants[i].NoteGenerale;      
                }    
            }   
                M = S/info;
                printf("La Moyenne Generale du departement de Mathematique et Informatique est : %d ",M);
                printf("\n---------------------------------------------------------------------------------------\n");
                
            
            break;
        
        case 2:
            for(i=0;i<nombretotale;i++){
                if(strcmp(Etudiants[i].Departement,"Physique") == 0){
                        S += Etudiants[i].NoteGenerale; 

                }    
            }
            M = S/ph;
            printf("La Moyenne Generale du departement du Physique est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 3:
            for(i=0;i<nombretotale;i++){
            if(strcmp(Etudiants[i].Departement,"Chimie") == 0){
                    S += Etudiants[i].NoteGenerale; 

                }
            }
            M = S/ch;
            printf("La Moyenne Generale du departement du Chimie est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 4:
            for(i=0;i<nombretotale;i++){
            if(strcmp(Etudiants[i].Departement,"Biologie") == 0){          
                    S += Etudiants[i].NoteGenerale; 

                }
            }
            M = S/bg;
            printf("La Moyenne Generale du departement du Biologie est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 5:
            for(i=0;i<nombretotale;i++){
            if(strcmp(Etudiants[i].Departement,"Sciences de la Terre") == 0){
                    S += Etudiants[i].NoteGenerale; 

                }
            }
            M = S/svt;
            printf("La Moyenne Generale du departement de Sciences de la Terre est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 6:
            for(i=0;i<nombretotale;i++){
                if(strcmp(Etudiants[i].Departement,"Sciences Economiques et de Gestion") == 0){
                        S += Etudiants[i].NoteGenerale; 

                }
            }
            M = S/eco;
            printf("La Moyenne Generale du departement de Sciences Economiques et de Gestion est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 7:
            for(i=0;i<nombretotale;i++){
                if(strcmp(Etudiants[i].Departement,"Droit") == 0){
                        S += Etudiants[i].NoteGenerale; 

                    }
            }
            M = S/dr;
            printf("La Moyenne Generale du departement de Droit est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 8:
            for(i=0;i<nombretotale;i++){
                if(strcmp(Etudiants[i].Departement,"Geographie") == 0){
                        S += Etudiants[i].NoteGenerale; 

                }
            }
            M = S/gh;
            printf("La Moyenne Generale du departement de Geographie est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        case 9:
            for(i=0;i<nombretotale;i++){
                if(strcmp(Etudiants[i].Departement,"Anglais") == 0){
                        S += Etudiants[i].NoteGenerale; 

                }
            }
            M = S/ag;
            printf("La Moyenne Generale du departement de Anglais est : %d ",M);
            printf("\n---------------------------------------------------------------------------------------\n");
            
            break;
        
        default :
            printf("Choix invalide!! Entrer un nouveau choix :");
            break;
    }        
}

void MoynnUnvrste(){
    int S = 0;
    int M = 0;

    for(i=0;i<nombretotale;i++){
        S += Etudiants[i].NoteGenerale;
    }
    M = S/nombretotale;
    printf("\n La Moyenne Generale de l'Universite Entiere est : %d ", S);
}

void CalculMoynnGnrl(){
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("\t [1]-Moyenne Generale d'un Departement :\n");
    printf("\t [2]-Moyenne Generale de l'Universite Entiere :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Entrer votre choix :");
    scanf("%d",&Mdfction);
    printf("\n---------------------------------------------------------------------------------------\n");
    
    switch(Mdfction){
        case 1:
            MoynnDprtment();
            break;
        
        case 2:
            MoynnUnvrste();
            break;

        default :
            printf("Choix invalide!! Entrer un nouveau choix :");
            break;    
    }


}



int main(){
    int choix;

    
    printf("n---------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf(" ---------------------- Gestion des etudiants dans l'universite ----------------------\n");
    
    do{
        printf("---------------------------------------------------------------------------------------\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf("\t Appuyer sur [1] pour Ajouter les informations un etudiant :\n");
        printf("\t Appuyer sur [2] pour Manipuler les informations d'un etudiant :\n");
        printf("\t Appuyer sur [3] pour Afficher les informations de tous les etudiants :\n");
        printf("\t Appuyer sur [4] pour Afficher la moyenne generale de tous les etudiants :\n");
        printf("\t Appuyer sur [5] pour Afficher les statistiques de tous les etudiants :\n");
        printf("\t Appuyer sur [6] pour Rechercher les informations d'un etudiant :\n");
        printf("\t Appuyer sur [7] pour Trier les etudiants :\n");
        printf("\t Appuyer sur [8] pour Sortir du programme :\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf("---------------------------------------------------------------------------------------\n");
        printf("\t Veuillez entrer votre choix : ");
        scanf("%d",&choix);
        printf("---------------------------------------------------------------------------------------\n");
        printf("---------------------------------------------------------------------------------------\n");
        getchar();

        switch(choix){
            case 1:
                AjouterUnEtudiant();
                break;

            case 2:
                ModifierUnEtudiant();
                break;   
            
            case 3:
                AfficherTousEtudiant();
                break;

            case 4:
                CalculMoynnGnrl();
                break;

            case 5:
                    

           default :
                printf("Choix invalide!! Entrer un nouveau choix :");
                break; 
        
        }
    }while (choix != 8);

  
  
  return 0;  
}
