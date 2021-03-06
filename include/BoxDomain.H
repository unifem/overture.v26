/*
** This software is copyright (C) by the Lawrence Berkeley National
** Laboratory.  Permission is granted to reproduce this software for
** non-commercial purposes provided that this notice is left intact.
**  
** It is acknowledged that the U.S. Government has rights to this
** software under Contract DE-AC03-765F00098 between the U.S.  Department
** of Energy and the University of California.
**  
** This software is provided as a professional and academic contribution
** for joint exchange. Thus it is experimental, is provided ``as is'',
** with no warranties of any kind whatsoever, no support, no promise of
** updates, or printed documentation. By using this software, you
** acknowledge that the Lawrence Berkeley National Laboratory and Regents
** of the University of California shall have no liability with respect
** to the infringement of other copyrights by any part of this software.
**  
** For further information about this software, contact:
** 
**         Dr. John Bell
**         Bldg. 50D, Rm. 129,
**         Lawrence Berkeley National Laboratory
**         Berkeley, CA, 94720
**         jbbell@lbl.gov
*/

#ifndef _BOXDOMAIN_H_
#define _BOXDOMAIN_H_

//
// $Id: BoxDomain.H,v 1.3 2008/12/03 17:54:46 chand Exp $
//

#include <stdlib.h>
//kkc 081124 #include <iostream.h>
#include <iostream>

#include <Boolean.H>
#include <IndexType.H>
#include <Box.H>
#include <IntVect.H>
#include <BoxList.H>


//
// Forward declaration of our BoxDomain iterator class.
//
class BoxDomainIterator;

//
//@Man:
//@Memo: A List of Disjoint Boxes
/*@Doc:

  A BoxDomain is a BoxList with the restriction that Boxes in the list
  are disjoint.

  Note that a BoxDomain is NOT a BoxList due to the protected inheritance.

  This is a concrete class, not a polymorphic one.
*/

class BoxDomain
    : protected BoxList
{
    //
    // BoxDomainIterator is a friend of ours :-)
    //
    friend class BoxDomainIterator;

public:
    //
    //@ManDoc: Output a BoxDomain to an ostream is ASCII format.
    //
    friend std::ostream& operator<< (std::ostream&         os,
                                const BoxDomain& bd);
    //
    //@ManDoc: Construct an empty BoxDomain of IndexType::TheCellType().
    //
    BoxDomain ();
    //
    //@ManDoc: Construct an empty BoxDomain of IndexType itype.
    //
    BoxDomain (IndexType itype);
    //
    //@ManDoc: The copy constructor.
    //
    BoxDomain (const BoxDomain& rhs);
    //
    //@ManDoc: The assignment operator.
    //
    BoxDomain& operator= (const BoxDomain& rhs);
    //
    //@ManDoc: The destructor.
    //
    ~BoxDomain ();
    //
    //@ManDoc: Add a Box to the domain.
    //
    void add (const Box& b);
    //
    //@ManDoc: Add all Boxes in the BoxList to the domain.
    //
    void add (const BoxList& bl);
    //
    //@ManDoc: Remove a box from the domain.
    //
    BoxDomain& rmBox (const Box& b);

    /*@ManDoc: Returns True if this BoxDomain is valid.  Checks for
               disjointness. Returns true if the BoxDomain is empty.
    */
    bool ok () const;
    //
    //@ManDoc: Access the Box to which the iterator points.
    //
    const Box& operator[] (const BoxDomainIterator& bli) const;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::clear;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::length;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::isEmpty;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::isNotEmpty;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::minimalBox;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::ixType;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::minimize;
    //
    //@ManDoc: Promoted from BoxList.
    //
    BoxList::simplify;
    //
    //@ManDoc: Create a BoxList from this BoxDomain.
    //
    BoxList boxList () const;
    //
    //@ManDoc: Are the BoxDomains equal?
    //
    bool operator== (const BoxDomain& rhs) const;
    //
    //@ManDoc: Are the BoxDomains not equal?
    //
    bool operator!= (const BoxDomain& rhs) const;
    //
    //@ManDoc: True if IntVect is within any of the Boxes in this BoxDomain.
    //
    bool contains (const IntVect& v) const;

    /*@ManDoc: True if the Box is within any of the Boxes in this BoxDomain.
               The Box must also have the same IndexType as those in this
               BoxDomain.
    */
    bool contains (const Box& b) const;
    //
    //@ManDoc: True if all Boxes in bl are contained in this BoxDomain.
    //
    bool contains (const BoxList& bl) const;
    //
    //@ManDoc: Applies Box::shift(int,int) to each Box in the BoxDomain.
    //
    BoxDomain& shift (int dir,
                      int nzones);
    //
    //@ManDoc: Applies Box::shiftHalf(int,int) to each Box in the BoxDomain.
    //
    BoxDomain& shiftHalf (int dir,
                          int num_halfs);

    //
    //@ManDoc: Applies Box::shiftHalf(IntVect) to each Box in BoxDomain.
    //
    BoxDomain& shiftHalf (const IntVect& iv);
    //
    //@ManDoc: Refine all Boxes in the domain by the refinement ratio.
    //
    BoxDomain& refine (int ratio);

    /*@ManDoc: Refine all Boxes in the domain by the refinement ratio
               and return the result in dest.
    */
    friend inline void refine (BoxDomain&       dest,
                               const BoxDomain& fin,
                               int              ratio);
    //
    //@ManDoc: Coarsen all Boxes in the domain by the refinement ratio.
    //
    BoxDomain& coarsen (int ratio);

    /*@ManDoc: Coarsen all Boxes in the domain by the refinement ratio.
               The result is placed into a new BoxDomain.
    */
    friend inline void coarsen (BoxDomain&       dest,
                                const BoxDomain& fin,
                                int              ratio);
    //
    //@ManDoc: Intersect this BoxDomain with Box b.
    //
    BoxDomain& intersect (const Box& b);

    /*@ManDoc: Compute the intersection of BoxDomain fin with Box b
               and place the result into BoxDomain dest. 
    */
    friend inline void intersect (BoxDomain&       dest,
                                  const BoxDomain& fin,
                                  const Box&       b);
    //
    //@ManDoc: Grow each Box by size sz.
    //
    BoxDomain& accrete (int sz);

    /*@ManDoc: Grow each Box in BoxDomain fin by size sz and place
               the result into BoxDomain dest.
    */
    friend inline void accrete (BoxDomain&       dest,
                                const BoxDomain& fin,
                                int              sz);
    //
    //@ManDoc: Creates the complement of BoxDomain bl in Box b.
    //
    BoxDomain& complementIn (const Box&       b,
                             const BoxDomain& bl);
    //
    //@ManDoc: Returns the complement of BoxDomain bl in Box b.
    //
    friend inline BoxDomain complementIn (const Box&       b,
                                          const BoxDomain& bl);
};

//
//@Man:
//@Memo: An Iterator for BoxDomain
/*@Doc:

  An iterator class allowing traversal over the Boxes in a BoxDomain.

  This class does support a coping -- the compiler will generate
  a copy constructor on the fly if you need one.

  This class also does NOT provide a default constructor or
  a copy assignment operator.
*/

class BoxDomainIterator
    : public ListIterator<Box>
{
public:
    //
    //@ManDoc: Construct a BoxDomianIterator on the supplied BoxDomain.
    //
    BoxDomainIterator (const BoxDomain& bl)
        : ListIterator<Box>(bl.lbox) {}
};

//
// Inlines.
//

inline
const Box&
BoxDomain::operator[] (const BoxDomainIterator& bli) const
{
    return lbox[bli];
}

inline
bool
BoxDomain::contains (const IntVect& v) const
{
    return BoxList::contains(v);
}

inline
bool
BoxDomain::contains (const Box& b) const
{
    return BoxList::contains(b);
}

inline
bool
BoxDomain::contains (const BoxList& bl) const
{
    return BoxList::contains(bl);
}

inline
BoxDomain&
BoxDomain::intersect (const Box& b)
{
    BoxList::intersect(b);
    boxAssert(ok());
    return *this;
}

inline
void
intersect (BoxDomain&       dest,
           const BoxDomain& fin,
           const Box&       b)
{
   dest = fin;
   dest.intersect(b);
}

inline
BoxDomain&
BoxDomain::refine (int ratio)
{
    BoxList::refine(ratio);
    boxAssert(ok());
    return *this;
}

inline
void
refine (BoxDomain&       dest,
        const BoxDomain& fin,
        int              ratio)
{
    dest = fin;
    dest.refine(ratio);
}

inline
void
accrete (BoxDomain&       dest,
         const BoxDomain& fin,
         int              sz)
{
    dest = fin;
    dest.accrete(sz);
}

inline
void
coarsen (BoxDomain&       dest,
         const BoxDomain& fin,
         int              ratio)
{
    dest = fin;
    dest.coarsen(ratio);
}

inline
BoxDomain&
BoxDomain::complementIn (const Box&       b,
                         const BoxDomain& bl)
{
    BoxList::complementIn(b,bl);
    boxAssert(ok());
    return *this;
}

inline
BoxDomain
complementIn (const Box&       b,
              const BoxDomain& bl)
{
  // Commented out to handle Vertex centered case
  // *dq*    BoxDomain result;
    BoxDomain result(b.ixType());
    result.complementIn(b,bl);
    return result;
}

inline
BoxDomain&
BoxDomain::shift (int dir,
                  int nzones)
{
    BoxList::shift(dir, nzones);
    return *this;
}

inline
BoxDomain&
BoxDomain::shiftHalf (int dir,
                      int num_halfs)
{
    BoxList::shiftHalf(dir, num_halfs);
    return *this;
}

inline
BoxDomain&
BoxDomain::shiftHalf (const IntVect& iv)
{
    BoxList::shiftHalf(iv);
    return *this;
}

inline
BoxList
BoxDomain::boxList () const
{
    return BoxList(*this);
}

inline
bool
BoxDomain::operator== (const BoxDomain& rhs) const
{
    return BoxList::operator==(rhs);
}

inline
bool
BoxDomain::operator!= (const BoxDomain& rhs) const
{
    return !BoxList::operator==(rhs);
}

#endif /*_BOXDOMAIN_H_*/
