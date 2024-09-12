#include<stdio.h>
#include<string.h>



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
    int Departement;
    DateNaissance DateNssce;

}Etudiant;

Etudiant Etudiants[600];

char Departements[][35] = {"Mathematique et Informatique","Physique","Chimie","Biologie","Sciences de la Terre","Sciences Economiques et de Gestion"};
int NbrDprtmt = sizeof(Departements) / sizeof(Departements[0]);
int nombretotale = 0;


void DataProjet(){
    const char Noms[][20] = {"Ahmed", "Fatima", "Mohamed", "Ali", "Rachad", "Adam", "Ilyass", "Houssam", "Zahra", "Marwan"};
    const char Prenoms[][20] = {"Rochdi", "Zahraa", "Nabil", "Nour", "Bassel", "Rwan", "Rizki", "Motari", "Noura", "Sarawni"};
    const float NotesGnrl[] = {16, 14, 18, 12, 13, 17, 15, 19, 16, 14};
    const int Departements[] = {0, 1, 2, 1, 0, 2, 1, 0, 2, 1};
    const int Jours[] = {9, 5, 15, 25, 11, 3, 20, 30, 14, 8};
    const int Mois[] = {11, 6, 8, 12, 1, 3, 7, 10, 2, 4};
    const int Annees[] = {2001, 1999, 2000, 2002, 1998, 2001, 2001, 2000, 1999, 2001};


    for (int i = 0; i < 10; i++) {
        Etudiant etudiant;

        etudiant.NumeroUnique = nombretotale + 1;
        strcpy(etudiant.Nom, Noms[i]);
        strcpy(etudiant.Prenom, Prenoms[i]);
        etudiant.NoteGenerale = NotesGnrl[i];
        etudiant.Departement = Departements[i];
        etudiant.DateNssce.Jour = Jours[i];
        etudiant.DateNssce.Mois = Mois[i];
        etudiant.DateNssce.Annee = Annees[i];

        Etudiants[nombretotale] = etudiant;
        nombretotale++;
    }




}

void AffichageBoucle(){
    for(int i=0;i<nombretotale;i++){
        printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
        printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
        printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
        printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
        printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
        printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
        printf("\n---------------------------------------------------------------------------------------\n");
        printf("\n---------------------------------------------------------------------------------------\n");
        

    }
}

void RechchUnEtdtNom(){
    int i;
    char Nom[20];

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Veuillez Entrer le Nom de l'Etudiant a chercher :");
    scanf("%s",&Nom);
    printf("\n---------------------------------------------------------------------------------------\n");
    for(i=0;i<nombretotale;i++){
        if(strcmp(Etudiants[i].Nom,Nom) == 0){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");

        }
    }

}

void EtdtsCHQDeprtmt(){
    int choix;
    int nbr = 0;

    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Voici les Departements de l'Universite :\n");
    printf("---------------------------------------------------------------------------------------\n");
    for(int i=0;i<NbrDprtmt;i++){
        printf("[%d]-%s\n",i+1,Departements[i]);
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&choix);
    for (int j=0; j < nombretotale; j++){
        if(Etudiants[j].Departement == choix - 1){
             nbr ++;
                     
        }             
    }
    printf("Le Nombre des etudiants du Departement %s est : %d Etudiants. ",Departements[Etudiants[nombretotale].Departement],nbr);

}

void TriAlphabetiqueCroisst(){
    int i,j;
    int chng;   
    
    for(i=0;i<nombretotale - 1;i++)
            for (j=i;j<nombretotale;j++){
                if(strcmp(Etudiants[j].Nom,Etudiants[i].Nom)< 0){
                    Etudiant Chng  = Etudiants[i];
                    Etudiants[i] = Etudiants[j];
                    Etudiants[j] = Chng ;
                }
    }                                
    AffichageBoucle();    
    
}

void TriAlphabetiqueDecroisst(){
    int chng;   
    int i,j;

    for(i=0;i<nombretotale - 1;i++)
            for (j=i;j<nombretotale;j++){
                if(strcmp(Etudiants[j].Nom,Etudiants[i].Nom)> 0){
                    Etudiant Chng  = Etudiants[i];
                    Etudiants[i] = Etudiants[j];
                    Etudiants[j] = Chng ;
                }
    }                                
    AffichageBoucle();    

}

void TriNoteGnrlCroisst(){
    int chng;   
    int i,j;

    for(i=0;i<nombretotale - 1;i++)
            for (j=i;j<nombretotale;j++){
                if(Etudiants[j].NoteGenerale > Etudiants[i].NoteGenerale){
                    Etudiant Chng  = Etudiants[i];
                    Etudiants[i] = Etudiants[j];
                    Etudiants[j] = Chng ;
                }
    }                                
    AffichageBoucle();    
    
}

void TriNoteGnrlDecroisst(){
    int chng;   
    int i,j;
    
    for(i=0;i<nombretotale - 1;i++)
            for (j=i;j<nombretotale;j++){
                if(Etudiants[j].NoteGenerale < Etudiants[i].NoteGenerale){
                    Etudiant Chng  = Etudiants[i];
                    Etudiants[i] = Etudiants[j];
                    Etudiants[j] = Chng ;
                }
    }                                
    AffichageBoucle();    

}

void TriEtdtReussi(){
    int chng;

    
    for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NoteGenerale >= 10){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");

        }

        
    }

}

void MeillrsNotes(){
    printf("Les etudiants ayant les 3 meilleures notes sont :\n");
    for(int i=0;i<nombretotale - 1;i++)
            for (int j=i;j<nombretotale;j++){
                if(Etudiants[j].NoteGenerale>Etudiants[i].NoteGenerale){
                    Etudiant Chng  = Etudiants[i];
                    Etudiants[i] = Etudiants[j];
                    Etudiants[j] = Chng ;
                }
    }                          
    for(int i=0;i<3;i++){
        printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
        printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
        printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
        printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
        printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
        printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
        printf("\n---------------------------------------------------------------------------------------\n");
        printf("\n---------------------------------------------------------------------------------------\n");
        
    }

}

void EtdMentionTRBien(){
    
    printf("La liste des Etudiants avec Mention Tres Bien :\n ");
    for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NoteGenerale >= 16 && Etudiants[i].NoteGenerale < 20 ){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");
            
        }
    
    }
}

void EtdMentionBien(){


     printf("La liste des Etudiants avec Mention Bien :\n");
     for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NoteGenerale >= 14 && Etudiants[i].NoteGenerale < 16 ){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");

        }
    
    }

}

void EtdMentionACBien(){
     
     printf("La liste des Etudiants avec Mention Assez Bien :\n");
     for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NoteGenerale >= 12 && Etudiants[i].NoteGenerale < 14 ){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");

        }
    
    }

}

void EtdMentionPassbl(){
     
     printf("La liste des Etudiants avec Mention Passable :\n");
     for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NoteGenerale >= 10 && Etudiants[i].NoteGenerale < 12 ){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");

        }
    
    }

}

void EtdEchec(){
     
     printf("La liste des Etudiants qui n'ont pas reussi :\n");
     for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NoteGenerale < 10 && Etudiants[i].NoteGenerale > 0){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",i+1,Etudiants[i].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",i+1,Etudiants[i].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",i+1,Departements[Etudiants[i].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",i+1,Etudiants[i].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",i+1,Etudiants[i].DateNssce.Jour,Etudiants[i].DateNssce.Mois,Etudiants[i].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");

        }
    
    }

}

void AfficherNbrTtle(){
    printf("Voici le Nombre Total des Etudiants de l'Universite : %d Etudiants.", nombretotale );
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
    AffichageBoucle();
    
}

void SupprimerUnEtudiant(){
    int i,j;
    int choix;
    int NumeroUnique;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Veuillez entrer le Numero Unique de l'Etudiant :");
    scanf("%d",&NumeroUnique);
    printf("Vous voulez vraiment supprimer les informations de cet Etudiant :\n");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("[1]-Confirmer la suppression : \n");
    printf("[2]-Retourner au Menu Principale : \n");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("Entrer votre choix :");
    scanf("%d",&choix);
    printf("\n---------------------------------------------------------------------------------------\n"); 
    switch(choix){
        case 1:
        for(i=0;i<nombretotale;i++)
            if(Etudiants[i].NumeroUnique == NumeroUnique)
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
    int choix;
    int NumeroUnique;
    int indice;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Veuillez entrer le Numero Unique de l'Etudiant :");
    scanf("%d",&NumeroUnique);
    printf("\n---------------------------------------------------------------------------------------\n");
    for(int i=0;i<nombretotale;i++){
        if(Etudiants[i].NumeroUnique == NumeroUnique){
            indice = i;
            break;
        }
    }

    printf("---------------------------------------------------------------------------------------\n"); 
    printf("Quelles informations voulez-vous Modifier :");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("\t[1]-Nom : \n \t[2]-Prenom : \n \t[3]-Date de Naissance : \n \t[4]-Departement \n \t[5]-Note Generale : \n \t[6]-Toutes les Informations : \n");
    printf("---------------------------------------------------------------------------------------\n"); 
    printf("\tEntrer votre Choix :");
    scanf("%d",&choix);
    switch(choix){
        
        case 1:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Nom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[indice].Nom);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tLe Nom est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n");                

        break;   
        
        case 2:

            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Prenom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[indice].Prenom);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tLe Prenom est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
      
        break;   
        
        case 3:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer la nouvelle Date de Naissance :\n");
            printf("\t Entrer le nouveau Jour :");
            scanf("%d",&Etudiants[indice].DateNssce.Jour);
            printf("\t Entrer le nouveau Mois :");
            scanf("%d",&Etudiants[indice].DateNssce.Mois);
            printf("\t Entrer la nouvelle Annee :");
            scanf("%d",&Etudiants[indice].DateNssce.Annee);
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tLa Date de Naissance est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
            break;

        case 4:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf(" Veuillez choisir le nouveau Departement de l'etudiant :");
            printf("---------------------------------------------------------------------------------------\n");
            for(int i=0;i<NbrDprtmt;i++){
                printf("[%d]-%s\n",i+1,Departements[i]);
            }
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t Choisissez un Departement :");
            scanf("%d",&choix);
            Etudiants[indice].Departement = choix - 1;

            printf("---------------------------------------------------------------------------------------\n");
            printf("\tLe Departement est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n");
            break;

        case 5:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer la Nouvelle Note Generale :");
            scanf("%f",&Etudiants[indice].NoteGenerale);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tLa Note Generale est modifie avec succes.");
            printf("\n---------------------------------------------------------------------------------------\n"); 
            break;

        case 6:
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Nom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[indice].Nom);
            printf("\n---------------------------------------------------------------------------------------\n"); 
            printf("\tEntrer le nouveau Prenom de l'Etudiant :");
            scanf(" %[^\n]s",&Etudiants[indice].Prenom);
            printf("---------------------------------------------------------------------------------------\n"); 
            printf("\t Veuillez entrer la nouvelle Date de Naissance :\n");
            printf("\t Entrer le nouveau Jour :");
            scanf("%d",&Etudiants[indice].DateNssce.Jour);
            printf("\t Entrer le nouveau Mois :");
            scanf("%d",&Etudiants[indice].DateNssce.Mois);
            printf("\t Entrer la nouvelle Annee :");
            scanf("%d",&Etudiants[indice].DateNssce.Annee);
            printf("---------------------------------------------------------------------------------------\n"); 
            printf(" Veuillez choisir le Departement de l'etudiant :");
            printf("---------------------------------------------------------------------------------------\n");
            for(int i=0;i<NbrDprtmt;i++){
                printf("[%d]-%s\n",i+1,Departements[i]);
            }
            printf("---------------------------------------------------------------------------------------\n");
            printf("\t Choisissez un Departement :");
            scanf("%d",&choix);
            Etudiants[indice].Departement = choix - 1;

            printf("\t Veuillez entrer la Nouvelle Note Generale :");
            scanf("%f",&Etudiants[indice].NoteGenerale);
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
    int choix;
    int i;

    printf("\t Veuillez entrer le Nom de l'etudiant :");
    scanf(" %[^\n]s",&Etudiants[nombretotale].Nom);
    
    printf("\t Veuillez entrer le Prenom de l'etudiant :");
    scanf(" %[^\n]s",&Etudiants[nombretotale].Prenom);
    
    printf("\t Veuillez entrer la Note Generale de l'etudiant :");
    scanf("%f",&Etudiants[nombretotale].NoteGenerale);
   
    printf("\t Veuillez entrer la Date de Naissance de l'Etudiant:\n");
    printf("\t Entrer le Jour :");
    scanf("%d",&Etudiants[nombretotale].DateNssce.Jour);
    printf("\t Entrer le Mois :");
    scanf("%d",&Etudiants[nombretotale].DateNssce.Mois);
    printf("\t Entrer l'Annee :");
    scanf("%d",&Etudiants[nombretotale].DateNssce.Annee);
    
    printf(" Veuillez choisir le Departement de l'etudiant :");
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0;i<NbrDprtmt;i++){
        printf("[%d]-%s\n",i+1,Departements[i]);
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&choix);
    Etudiants[i].Departement = choix - 1;
    
    Etudiants[nombretotale].NumeroUnique = nombretotale + 1;
    nombretotale ++;
    printf("---------------------------------------------------------------------------------------\n");   
    printf("Les informations de l'Etudiant sont ajoutees avec succes.\n");
    printf("---------------------------------------------------------------------------------------\n");

}

void AjoutMultiple(){
   int NbrAjout;
   int choix;

    printf("---------------------------------------------------------------------------------------\n");
    printf("Veuillez saisir le nombre des Etudiants que vous voulez Ajouter :");
    scanf("%d",&NbrAjout);
    printf("---------------------------------------------------------------------------------------\n");
    for(int i=0;i<NbrAjout;i++){
        printf("\t Veuillez entrer le Nom de l'etudiant %d :",i+1);
        scanf(" %[^\n]s",&Etudiants[i].Nom);
        
        printf("\t Veuillez entrer le Prenom de l'etudiant %d :",i+1);
        scanf(" %[^\n]s",&Etudiants[i].Prenom);
        
        printf("\t Veuillez entrer la Note Generale de l'etudiant %d :",i+1);
        scanf("%f",&Etudiants[i].NoteGenerale);
    
        printf("\t Veuillez entrer la Date de Naissance de l'Etudiant %d :\n",i+1);
        printf("\t Entrer le Jour :");
        scanf("%d",&Etudiants[i].DateNssce.Jour);
        printf("\t Entrer le Mois :");
        scanf("%d",&Etudiants[i].DateNssce.Mois);
        printf("\t Entrer l'Annee :");
        scanf("%d",&Etudiants[i].DateNssce.Annee);
        
        printf(" Veuillez choisir le Departement de l'etudiant %d :",i+1);
        printf("---------------------------------------------------------------------------------------\n");
        for(int j=0;j<NbrDprtmt;j++){
            printf("\t[%d]-%s\n",j+1,Departements[j]);
        }
        printf("---------------------------------------------------------------------------------------\n");
        printf("\t Choisissez un Departement :");
        scanf("%d",&choix);
        Etudiants[i].Departement = choix - 1;

        Etudiants[i].NumeroUnique = nombretotale + 1;
        nombretotale ++;
        printf("---------------------------------------------------------------------------------------\n");
        printf("Les informations de l'Etudiant %d se sont ajoutees avec succes.\n",i+1);
        printf("---------------------------------------------------------------------------------------\n");
    }
    printf("Les informations de tous ces Etudiants se sont ajoutes avec succes.\n");
}

void AjouterUnEtudiant(){
    int choix;

    printf("\t Quel type d'Ajout vous Voulez :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t [1] Un Ajout Simple :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t [2] Un Ajout Multiple :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez votre type d'Ajout :");
    scanf("%d",&choix);
    printf("---------------------------------------------------------------------------------------\n");
    getchar();
    
    switch(choix){
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
    int NumeroUnique;
    int choix;
    int i;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Choisissez une Option : \n");
    printf("\t[1]-Modifier les informations d'un Etudiant : \n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t[2]-Supprimer les informations d'un Etudiant : \n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\tEntrer votre choix : ");
    scanf("%d",&choix);
    switch(choix){
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

void NbrReussiDprtm(){
    int choix;
    int nbr = 0;

    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Voici les Departements de l'Universite :\n");
    printf("---------------------------------------------------------------------------------------\n");
    for(int i=0;i<NbrDprtmt;i++){
        printf("[%d]-%s\n",i+1,Departements[i]);
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&choix);
    for (int j=0; j < nombretotale; j++){
        if(Etudiants[j].Departement == choix - 1 && Etudiants[j].NoteGenerale >= 10){
             nbr ++;
                     
        }             
    }
    printf("Le Nombre des etudiants qui ont reussi dans le Departement du %s est : %d Etudiants. ",Departements[Etudiants[nombretotale].Departement],nbr);
}

void MoynnDprtment(){
    float S = 0;
    float M = 0;
    int choix;
    int dvsr = 0;

    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Voici les Departement de l'Universite :\n");
    printf("---------------------------------------------------------------------------------------\n");
    for(int i=0;i<NbrDprtmt;i++){
        printf("[%d]-%s\n",i+1,Departements[i]);
    }
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Choisissez un Departement :");
    scanf("%d",&choix);
    for (int j=0; j < nombretotale; j++){
        if(Etudiants[j].Departement == choix - 1){
                S += Etudiants[j].NoteGenerale; 
                dvsr ++;     
        }             
    }
    
    M = S/dvsr;
    printf("La Moyenne Generale du departement de Mathematique et Informatique est : %.2f ",M);
    printf("\n---------------------------------------------------------------------------------------\n");  
    }
    
void MoynnUnvrste(){
    float S = 0;
    float M = 0;

    for(int i=0;i<nombretotale;i++){
        S += Etudiants[i].NoteGenerale;
    }
    M = S/nombretotale;
    printf("\n La Moyenne Generale de l'Universite Entiere est : %.2f ", M);
}

void CalculMoynnGnrl(){
    int choix;
    
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("\t [1]-Moyenne Generale d'un Departement :\n");
    printf("\t [2]-Moyenne Generale de l'Universite Entiere :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\t Entrer votre choix :");
    scanf("%d",&choix);
    printf("\n---------------------------------------------------------------------------------------\n");
    
    switch(choix){
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

void EtudiantSeuil(){
    int choix;

    printf("\n---------------------------------------------------------------------------------------\n");
    char T[][30] = {"Tres Bien","Bien","Assez Bien","Passable","Echec"};
    for(int i=0;i<5;i++){
        printf("[%d]-%s:",i+1,T[i]);
    }
    printf("Veuillez saisir votre choix :");
    scanf("%d",&choix);
    printf("\n---------------------------------------------------------------------------------------\n");
    switch(choix){
        case 1:
              EtdMentionTRBien();
              break;

        case 2:
              EtdMentionBien();
              break;   

        case 3:
              EtdMentionACBien();
              break;       
             
        case 4:
              EtdMentionPassbl();
              break;     
        
        case 5:
              EtdEchec();
              break;

        default : 
               printf("Choix invalide !!!");
               break;      

    }


}

void Statistiques(){
    int choix;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("\t[1]-Afficher le nombre total d'etudiants de l'Universite :\n");
    printf("\t[2]-Afficher le nombre d'etudiants dans chaque departement :\n");
    printf("\t[3]-Afficher les etudiants ayant une moyenne generale superieure a un certain seuil :\n");
    printf("\t[4]-Afficher les 3 etudiants ayant les meilleures notes :\n");
    printf("\t[5]-Afficher le nombre d'etudiants ayant reussi dans chaque departement :\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\tVeuillez entrer un choix :");
    scanf("%d",&choix);
    printf("\n---------------------------------------------------------------------------------------\n");


    switch(choix){
        case 1:
            AfficherNbrTtle();
            break;

        case 2:
            EtdtsCHQDeprtmt();
            break;
        
        case 3:
            EtudiantSeuil();
            break;

        case 4:
            MeillrsNotes();
            break;

        case 5:
            NbrReussiDprtm();
            break;
                
        case 6:
            printf("Retour au Menu Principale :)");
            return;        
                
        default :
            printf("Choix invalide !!!");
            break;



    }

}

void TriEtudiants(){
    int choix;
    
    printf("\n---------------------------------------------------------------------------------------\n");
    char T[][50] = {"Tri par Nom (A-Z)","Tri par Nom (Z-A)","Tri par Note (Plus Eleve au Plus Faible)","Tri par Note (Plus Faible au Plus Eleve)"};
    for(int i=0;i<4;i++){
        printf("\t[%d]-%s:\n",i+1,T[i]);
    }
    printf("Veuillez choisir le type de tri :");
    scanf("%d",&choix);
    printf("\n---------------------------------------------------------------------------------------\n");
    switch(choix){
        
        case 1:
            TriAlphabetiqueCroisst();
            break;

        case 2:
            TriAlphabetiqueDecroisst();
            break;

        case 3:
            TriNoteGnrlDecroisst();
            break;

        case 4:
            TriNoteGnrlCroisst();
            break;            

        case 5:
            TriEtdtReussi();
            break;
        
        default :
            printf("Choix invalide !!!");
            break;
    }

}

void ListeDprtmt(){
    int choix;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Voici les Departements de l'Universite :\n");
    for(int i=0;i<NbrDprtmt;i++){
        printf("[%d]-%s\n",i+1,Departements[i]);
    }
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Veuillez Choisir un Departement :");
    scanf("%d",&choix);
    for (int j=0; j < nombretotale; j++){
        if(Etudiants[j].Departement == choix - 1){
            printf("\tLa Note Generale de l'Etudiant %d : %.2f\n",j+1,Etudiants[j].NoteGenerale);
            printf("\tLe Nom de l'Etudiant %d : %s.\n",j+1,Etudiants[j].Nom);
            printf("\tLe Prenom de l'Etudiant %d : %s.\n",j+1,Etudiants[j].Prenom);
            printf("\tLe Departement de l'Etudiant %d : %s.\n",j+1,Departements[Etudiants[j].Departement]);
            printf("\tLe Numero Unique de l'Etudiant %d : [%d]\n",j+1,Etudiants[j].NumeroUnique);
            printf("\tLa Date de Naissance de l'Etudiant %d : [ %d-%d-%d ]\n",j+1,Etudiants[j].DateNssce.Jour,Etudiants[j].DateNssce.Mois,Etudiants[j].DateNssce.Annee);
            printf("\n---------------------------------------------------------------------------------------\n");
            printf("\n---------------------------------------------------------------------------------------\n");
             
                     
        }             
    }
    

}

void RechchTtlEtds(){
    int choix;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("[1]-Chercher un Etudiant par son Nom :\n");
    printf("[1]-Afficher la liste des Etudiants dans un Departement :\n");
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Veuillez entrer un choix :");
    scanf("%d",&choix);
    switch(choix){
        case 1:
            RechchUnEtdtNom();
            break;

        case 2:
            ListeDprtmt();
            break;

        default :
            printf("Choix invalide !!!");
            break;        
   
    }






}

int main(){
    
    DataProjet();
    
    int choix;

    
    printf("\n---------------------------------------------------------------------------------------\n");
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
                Statistiques();
                break;
                    
            case 6:
                RechchTtlEtds();
                break;

            case 7:
                TriEtudiants();
                break;            

           
           default :
                printf("Choix invalide!! Entrer un nouveau choix :");
                break; 
        
        }
    }while (choix != 8);

  
  
  return 0;  
}
