int mangeTomate(Puceron puceron, Potager) {
/* fonction qui remet l'état de croissance d'une tomate "mangeable" a 0, si un
 puceron se trouve sur la même case */
 if ((*Potager[puceron.coordPuceron.x][puceron.coordPuceron.y]).tomateCase.etatCroissance>4) {
    mortTomate((*Potager[puceron.coordPuceron.x][puceron.coordPuceron.y]).tomateCase);
    return 1; //renvoie 1 comme booléen
 }
 else {
    return 0;
 }
}

void reproductionPuceron(Puceron* puceron, Potager) {
    if (mangeTomate(&puceron, Potager)==1) { //fonction qui renvoie true ou false si une tomate "mangeable" est sur la meme case qu'un puceron
        (*puceron).compteurReproduction=(*puceron).compteurReproduction+1;
    }
    else {
        (*puceron).compteurReproduction=0;
    }
    if ((*puceron).compteurReproduction==5) {
        ajoutePuceron(Puceron* puceron, )
    }
};

void vieillissementPuceron(Puceron* puceron, ensemblePuceron* ensPuc, Potager) {
    if ((*puceron).compteurVie==10) {
        enlevePuceron(&puceron, ensPuc, Potager);
    }
    else {
        (*puceron).compteurVie=(*puceron).compteurVie+1;
    }
};

void enlevePuceron(Puceron puceron, ensemblePuceron* ensPuc, Potager) {
    (*ensPuc).tab[puceron.index]=(*ensPuc).tab[(*ensPuc).(nbPuceron-1)]; //remplace le puceron en position INDEX par le dernier puceron de l'ensemble Puceron
    (*ensPuc).tab[puceron.index].index=puceron.index; //réattribue le bon index au puceron qui vient detre déplacé
    (*ensPuc).nbPuceron=(*ensPuc).nbPuceron-1; //corrige le nombre de puceron total dans l'ensemble Puceron
    Potager[puceron.coordPuceron.x][puceron.coordPuceron.y].(*puceronCase)=NULL;
};

void directionPuceron(Puceron* puceron) {

} ;

void ajoutePuceron(Puceron puceron, ensemblePuceron* ensPuc) {
    if ((*ensPuc).nbPuceron < 900) {
        (*ensPuc).tab[(*ensPuc).nbPuceron]=puceron;
        
    }
}

