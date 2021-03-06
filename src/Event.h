#ifndef EVENT_H
#define EVENT_H

///////////////////
//  Term Event   //
///////////////////

//References//
//-----------//
#include "Term.h"
#include "Stamp.h"

//Data structure//
//--------------//
#define EVENT_TYPE_GOAL 1
#define EVENT_TYPE_BELIEF 2
#define EVENT_TYPE_DELETED 0
typedef struct {
    Term term;
    //Term_HASH_TYPE term_hash;
    char type; //either JUDGMENT or GOAL
    Truth truth;
    Stamp stamp;
    long occurrenceTime;
    int operationID; //automatically obtained from Term on input
    bool processed;
    bool propagated;
    char debug[30];
} Event;

//Methods//
//-------//
//Init/Reset module
void Event_INIT();
//Assign a new name to an event
void Event_SetTerm(Event *event, Term term);
//construct an input event
Event Event_InputEvent(Term term, char type, Truth truth, long currentTime);
//print event
void Event_Print(Event *event);

#endif
