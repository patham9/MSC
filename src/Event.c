#include "Event.h"

void Event_SetTerm(Event *event, Term term)
{
    event->term = term;
    //Generate hash too:
    //event->term_hash = Term_Hash(&term);
}

long base = 1;
Event Event_InputEvent(Term term, char type, Truth truth, long currentTime)
{
    return (Event) { .term = term,
                     /*.term_hash = Term_Hash(&term),*/
                     .type = type, 
                     .truth = truth, 
                     .stamp = (Stamp) { .evidentalBase = { base++ } }, 
                     .occurrenceTime = currentTime };
}

void Event_INIT()
{
    base = 1;
}

void Event_Print(Event *event)
{
    printf("Event: %s\n", event->debug);
    Term_Print(&event->term);
    //printf("Term hash=%d", event->term_hash);
    printf(event->type == EVENT_TYPE_GOAL ? "type=goal\n" : (EVENT_TYPE_BELIEF ? "type=belief\n" : "type=deleted\n" ));
    printf("operationID=%d\n", event->operationID);
    Truth_Print(&event->truth);
    Stamp_print(&event->stamp);
    printf("occurrenceTime=%ld\n\n", event->occurrenceTime);
}

