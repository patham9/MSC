#ifndef BELIEF_H
#define BELIEF_H

//////////////////////
//  Implication     //
//////////////////////
//essentially allowing concepts to predict activations of others

//References//
//-----------//
#include "Term.h"
#include "Stamp.h"

//Data structure//
//--------------//
typedef struct {
    Term term;
    //Term_HASH_TYPE term_hash;
    Truth truth;
    Stamp stamp;
    //for deciding occurrence time of conclusion:
    long occurrenceTimeOffset;
    //for efficient spike propagation:
    void *sourceConcept;
    Term sourceConceptTerm; //to check whether it's still the same
    //Term_HASH_TYPE sourceConceptTermHash;
    char debug[100]; //++ DEBUG
} Implication;

//Methods//
//-------//
//Assign a new name to an implication
void Implication_SetTerm(Implication *implication, Term term);
void Implication_Print(Implication *implication);

#endif


