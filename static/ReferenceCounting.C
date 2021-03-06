#include "ReferenceCounting.h"

Integer ReferenceCounting::globalIDCounter = 0;

Integer ReferenceCounting::
incrementGlobalIDCounter()
{ 
  // return globalIDCounter++;   // *wdh* 020627 make the first id =1 
  // for OpenGL picking purposes, it is better to start with 1 instead of 0
  return ++globalIDCounter;   
}

void ReferenceCounting::consistencyCheck() const {
    if (referenceCount < 0) {
        cerr << "ReferenceCounting::consistencyCheck():  "
             << "ReferenceCounting::referenceCount is negative for "
             << getClassName() << " " << getGlobalID() << "." << endl;
        assert(referenceCount >= 0);
    } // end if
    if (uncountedReferences < 0) {
        cerr << "ReferenceCounting::consistencyCheck():  "
             << "ReferenceCounting::uncountedReferences is negative for "
             << getClassName() << " " << getGlobalID() << "." << endl;
        assert(uncountedReferences >= 0);
    } // end if
    if (globalID < 0) {
        cerr << "ReferenceCounting::consistencyCheck():  "
             << "ReferenceCounting::globalID is negative for"
             << getClassName() << "." << endl;
        assert(globalID >= 0);
    } // end if
    if (className != "ReferenceCounting") {
        cerr << "ReferenceCounting::consistencyCheck():  "
             << "ReferenceCounting::classname != \"ReferenceCounting\" for "
             << getClassName() << " " << getGlobalID() << "." << endl;
        assert(className == "ReferenceCounting");
    } // end if
    if (globalIDCounter < 0) {
        cerr << "ReferenceCounting::consistencyCheck():  "
             << "ReferenceCounting::globalIDCounter is negative." << endl;
        assert(globalIDCounter >= 0);
    } // end if
}

ostream& operator<<(ostream& s, const ReferenceCounting& x) {
    return s
      << "  getClassName()                    =  \""
      <<  x.getClassName() << "\"" << endl
      << "  getGlobalID()                     =  "
      <<  x.getGlobalID() << endl
      << "  getReferenceCount()               =  "
      <<  x.getReferenceCount();
}
