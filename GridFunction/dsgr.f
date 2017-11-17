! This file automatically generated from dsg.bf with bpp.


      subroutine divScalarGradFDeriv21R( nd,
     &    nd1a,nd1b,nd2a,nd2b,nd3a,nd3b,
     &    ndu1a,ndu1b,ndu2a,ndu2b,ndu3a,ndu3b,ndu4a,ndu4b, ! dimensions for u
     &    ndd1a,ndd1b,ndd2a,ndd2b,ndd3a,ndd3b,ndd4a,ndd4b, ! dimensions for deriv
     &    n1a,n1b,n2a,n2b,n3a,n3b, ca,cb,
     &    dx,
     &    u,s, deriv,
     &    a11,  ! work space
     &    derivOption, gridType, order, averagingType, dir1, dir2 )
c ===============================================================
c 2nd order, 1D, rectangular
c Conservative discretization of
c           div( s grad )
c           div( tensor grad )
c           derivativeScalarDerivative
c           
c ca,cb : assign components c=ca,..,cb (base 0)
c gridType: 0=rectangular, 1=non-rectangular
c order : 2 or 4
c rsxy : not used if rectangular
c h22 : 1/h**2 : for rectangular  
c ===============================================================

c      implicit none
      integer nd,
     & nd1a,nd1b,nd2a,nd2b,nd3a,nd3b,
     & ndu1a,ndu1b,ndu2a,ndu2b,ndu3a,ndu3b,ndu4a,ndu4b,
     & ndd1a,ndd1b,ndd2a,ndd2b,ndd3a,ndd3b,ndd4a,ndd4b,
     &  n1a,n1b,n2a,n2b,n3a,n3b, ca,cb,
     &  derivOption, gridType, order, averagingType, dir1, dir2

      integer arithmeticAverage,harmonicAverage
      parameter( arithmeticAverage=0,harmonicAverage=1 )
      integer laplace,divScalarGrad,derivativeScalarDerivative,
     & divTensorGrad
      parameter(laplace=0,divScalarGrad=1,derivativeScalarDerivative=2,
     & divTensorGrad=3)
      real s(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b,0:*)
      real u(ndu1a:ndu1b,ndu2a:ndu2b,ndu3a:ndu3b,ndu4a:ndu4b)
      real deriv(ndd1a:ndd1b,ndd2a:ndd2b,ndd3a:ndd3b,ndd4a:ndd4b)

      real a11(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real dx(1),h22(1),h21(1)

      real factor
      real urr

      integer i1,i2,i3,kd3,c,j1,j2,j3,n
      integer  m1a,m1b,m2a,m2b,m3a,m3b

c.......statement functions 
      ! Estimate D{-r}(i-1/2,j,k)
      urr(i1,i2,i3,c)=u(i1,i2,i3,c)-u(i1-1,i2,i3,c)

c.......end statement functions

      kd3=nd
      do n=1,nd
        h22(n)=1./dx(n)**2
        h21(n)=.5/dx(n)
      end do

! defineA21R()
      m1a=n1a-1
      m1b=n1b+1
      m2a=n2a
      m2b=n2b
      m3a=n3a
      m3b=n3b
c **** both divScalarGrad and derivativeScalarDerivative are the same in 1D *****
      if( averagingType .eq. arithmeticAverage )then
        factor=.5
! loopsDSG1(a11(j1,j2,j3) = factor*h22(1)*(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
        m1a=n1a
        do j3=m3a,m3b
          do j2=m2a,m2b
            do j1=m1a,m1b
              a11(j1,j2,j3)=factor*h22(1)*(s(j1,j2,j3,0)+s(j1-1,j2,j3,
     & 0))
            end do
          end do
        end do
        m1a=n1a-1
      else
c  Harmonic average
        factor=2.
        ! should be worry about division by zero?
! loopsDSG1(a11(j1,j2,j3)=s(j1,j2,j3,0)*h22(1)*s(j1-1,j2,j3,0)/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
        m1a=n1a
        do j3=m3a,m3b
          do j2=m2a,m2b
            do j1=m1a,m1b
              a11(j1,j2,j3)=s(j1,j2,j3,0)*h22(1)*s(j1-1,j2,j3,0)/(s(j1,
     & j2,j3,0)+s(j1-1,j2,j3,0))
            end do
          end do
        end do
        m1a=n1a-1
      end if

c      Evaluate the derivative
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-a11(i1,i2,i3)*urr(i1,i2,i3,c)))
      do c=ca,cb
        do i3=n3a,n3b
          do i2=n2a,n2b
            do i1=n1a,n1b
              deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-a11(
     & i1,i2,i3)*urr(i1,i2,i3,c))
            end do
          end do
        end do
      end do

      return
      end


      subroutine divScalarGradFDeriv22R( nd,
     &    nd1a,nd1b,nd2a,nd2b,nd3a,nd3b,
     &    ndu1a,ndu1b,ndu2a,ndu2b,ndu3a,ndu3b,ndu4a,ndu4b, ! dimensions for u
     &    ndd1a,ndd1b,ndd2a,ndd2b,ndd3a,ndd3b,ndd4a,ndd4b, ! dimensions for deriv
     &    n1a,n1b,n2a,n2b,n3a,n3b, ca,cb,
     &    dx, ! *****************
     &    u,s, deriv,
     &    a11,a22,a12,a21,  ! work space
     &    derivOption, gridType, order, averagingType, dir1, dir2 )
c ===============================================================
c 2nd order, 3D, rectangular
c Conservative discretization of
c           div( s grad )
c           div( tensor grad )
c           derivativeScalarDerivative
c  
c ca,cb : assign components c=ca,..,cb (base 0)
c derivOption : 0=laplace, 1=divScalarGrad, 2=derivativeScalarDerivative
c gridType: 0=rectangular, 1=non-rectangular
c order : 2 or 4
c rsxy : not used if rectangular
c h22 : 1/h**2 : for rectangular  
c ===============================================================

c      implicit none
      integer nd,
     & nd1a,nd1b,nd2a,nd2b,nd3a,nd3b,
     & ndu1a,ndu1b,ndu2a,ndu2b,ndu3a,ndu3b,ndu4a,ndu4b,
     & ndd1a,ndd1b,ndd2a,ndd2b,ndd3a,ndd3b,ndd4a,ndd4b,
     &  n1a,n1b,n2a,n2b,n3a,n3b, ca,cb,
     &  derivOption, gridType, order, averagingType, dir1, dir2

      integer arithmeticAverage,harmonicAverage
      parameter( arithmeticAverage=0,harmonicAverage=1 )
      integer laplace,divScalarGrad,derivativeScalarDerivative,
     & divTensorGrad
      parameter(laplace=0,divScalarGrad=1,derivativeScalarDerivative=2,
     & divTensorGrad=3)
      real s(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b,0:*)
      real u(ndu1a:ndu1b,ndu2a:ndu2b,ndu3a:ndu3b,ndu4a:ndu4b)
      real deriv(ndd1a:ndd1b,ndd2a:ndd2b,ndd3a:ndd3b,ndd4a:ndd4b)

      real a11(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a12(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a21(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a22(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)

      real dx(2),h22(2),h21(2)

      real factor
      real urr,uss,urs,usr,hh

      integer i1,i2,i3,kd3,c,j1,j2,j3,n
      integer  m1a,m1b,m2a,m2b,m3a,m3b

c.......statement functions 
      ! Estimate D{-r}(i-1/2,j,k)
      urr(i1,i2,i3,c)=u(i1,i2,i3,c)-u(i1-1,i2,i3,c)
      ! Estimate D{-s}(i-1/2,j+1/2,k)
      urs(i1,i2,i3,c)=(u(i1-1,i2+1,i3,c)+u(i1,i2+1,i3,c)-
     &     u(i1-1,i2-1,i3,c)-u(i1,i2-1,i3,c))
      ! Estimate D{-r}(i+1/2,j-1/2,k)
      usr(i1,i2,i3,c) = (u(i1+1,i2-1,i3,c) + u(i1+1,i2,i3,c) -
     &                   u(i1-1,i2-1,i3,c) - u(i1-1,i2,i3,c))
      ! Estimate D{-s}(i,j-1/2,k)
      uss(i1,i2,i3,c) = u(i1,i2,i3,c)-u(i1,i2-1,i3,c)
      ! Estimate D{-t}(i,j-1/2,k+1/2)
c      ust(i1,i2,i3,c) = (u(i1,i2-1,i3+1,c) + u(i1,i2,i3+1,c) - 
c     &                   u(i1,i2-1,i3-1,c) - u(i1,i2,i3-1,c))

      D0r(i1,i2,i3,c)=u(i1+1,i2,i3,c)-u(i1-1,i2,i3,c)
      D0s(i1,i2,i3,c)=u(i1,i2+1,i3,c)-u(i1,i2-1,i3,c)
      D0t(i1,i2,i3,c)=u(i1,i2,i3+1,c)-u(i1,i2,i3-1,c)

c.......end statement functions

      kd3=nd
      do n=1,nd
        h22(n)=1./dx(n)**2
        h21(n)=.5/dx(n)
      end do


! defineA22R()
      m1a=n1a-1
      m1b=n1b+1
      m2a=n2a-1
      m2b=n2b+1
      m3a=n3a
      m3b=n3b
      if( averagingType .eq. arithmeticAverage )then
        factor=.5
        if( derivOption.eq.divScalarGrad  )then
! loopsDSG1(a11(j1,j2,j3) = factor*h22(1)*(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
          m1a=n1a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a11(j1,j2,j3)=factor*h22(1)*(s(j1,j2,j3,0)+s(j1-1,j2,
     & j3,0))
              end do
            end do
          end do
          m1a=n1a-1
! loopsDSG2(a22(j1,j2,j3) = factor*h22(2)*(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
          m2a=n2a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a22(j1,j2,j3)=factor*h22(2)*(s(j1,j2,j3,0)+s(j1,j2-1,
     & j3,0))
              end do
            end do
          end do
          m2a=n2a-1
        else if( derivOption.eq.divTensorGrad )then
          ! form the coefficients and average
          !   we need to worry about the end points m1a=n1a-1 *wdh* 060210
          do j3=m3a,m3b
          do j2=m2a,m2b
            j2m1=max(j2-1,m2a)
          do j1=m1a,m1b
            j1m1=max(j1-1,m1a)
            a11(j1,j2,j3) = .5*(s(j1,j2,j3,0)+s(j1m1,j2,j3,0))/dx(1)**2
            a21(j1,j2,j3) = s(j1,j2,j3,1)/(4.*dx(1)*dx(2))
            a12(j1,j2,j3) = s(j1,j2,j3,2)/(4.*dx(1)*dx(2))
            a22(j1,j2,j3) = .5*(s(j1,j2,j3,3)+s(j1,j2m1,j3,3))/dx(2)**2
          end do
          end do
          end do
        else if( derivOption.eq.derivativeScalarDerivative )then
          if( dir1.eq.dir2 )then
            hh=h22(dir1+1)
          else
            hh=h21(dir1+1)*h21(dir2+1)
          end if
          if( dir1.eq.0 )then
! loopsDSG1(a11(j1,j2,j3) = factor*hh*(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
            m1a=n1a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=factor*hh*(s(j1,j2,j3,0)+s(j1-1,j2,j3,
     & 0))
                end do
              end do
            end do
            m1a=n1a-1
          else
! loopsDSG2(a11(j1,j2,j3) = factor*hh*(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
            m2a=n2a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=factor*hh*(s(j1,j2,j3,0)+s(j1,j2-1,j3,
     & 0))
                end do
              end do
            end do
            m2a=n2a-1
          end if
       else
         stop 1129
       end if
      else
c  Harmonic average
        factor=2.
        if( derivOption.eq.divScalarGrad  )then
          ! should be worry about division by zero?
! loopsDSG1(a11(j1,j2,j3) =s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*h22(1)*factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
          m1a=n1a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*h22(1)*
     & factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0))
              end do
            end do
          end do
          m1a=n1a-1
! loopsDSG2(a22(j1,j2,j3) =s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*h22(2)*factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
          m2a=n2a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a22(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*h22(2)*
     & factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0))
              end do
            end do
          end do
          m2a=n2a-1
        else if( derivOption.eq.divTensorGrad )then
          stop 2219
        else
          if( dir1.eq.dir2 )then
            hh=h22(dir1+1)
          else
            hh=h21(dir1+1)*h21(dir2+1)
          end if
          if( dir1.eq.0 )then
! loopsDSG1(a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*hh*factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
            m1a=n1a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*hh*
     & factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0))
                end do
              end do
            end do
            m1a=n1a-1
          else
! loopsDSG2(a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*hh*factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
            m2a=n2a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*hh*
     & factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0))
                end do
              end do
            end do
            m2a=n2a-1
          end if
        end if
      end if

c     Evaluate the derivative
      if( derivOption.eq.divScalarGrad )then
! loopsDSG(deriv(i1,i2,i3,c)=(  (a11(i1+1,i2  ,i3  )*urr(i1+1,i2  ,i3  ,c) - a11(i1,i2,i3)*urr(i1,i2,i3,c))+  (a22(i1  ,i2+1,i3  )*uss(i1  ,i2+1,i3  ,c) - a22(i1,i2,i3)*uss(i1,i2,i3,c))  ))
        do c=ca,cb
          do i3=n3a,n3b
            do i2=n2a,n2b
              do i1=n1a,n1b
                deriv(i1,i2,i3,c)=((a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urr(i1,i2,i3,c))+(a22(i1,i2+1,i3)*uss(i1,i2+1,i3,
     & c)-a22(i1,i2,i3)*uss(i1,i2,i3,c)))
              end do
            end do
          end do
        end do
      else if( derivOption.eq.divTensorGrad )then

c       ** here is the new symmetric formula ***
        do c=ca,cb
          do i3=n3a,n3b
            do i2=n2a,n2b
              do i1=n1a,n1b
                deriv(i1,i2,i3,c)=
     &              (
     &              (a11(i1+1,i2  ,i3  )*urr(i1+1,i2  ,i3  ,c) -
     &               a11(i1  ,i2  ,i3  )*urr(i1  ,i2  ,i3  ,c))+
     &              (a22(i1  ,i2+1,i3  )*uss(i1  ,i2+1,i3  ,c) -
     &               a22(i1  ,i2  ,i3  )*uss(i1  ,i2  ,i3  ,c))
     &             +(a21(i1  ,i2+1,i3  )*D0r(i1  ,i2+1,i3  ,c) -
     &               a21(i1  ,i2-1,i3  )*D0r(i1  ,i2-1,i3  ,c) +
     &               a12(i1+1,i2  ,i3  )*D0s(i1+1,i2  ,i3  ,c) -
     &               a12(i1-1,i2  ,i3  )*D0s(i1-1,i2  ,i3  ,c))
     &               )
              end do
            end do
          end do
        end do

      else
c       derivative scalar derivative
        if( dir1.eq.0 .and. dir2.eq.0 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-a11(i1,i2,i3)*urr(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urr(i1,i2,i3,c))
                end do
              end do
            end do
          end do
c          c=ca
c          i1=3
c          i2=3
c          i3=0
c          write(*,*) ' dsg: ca,cb,i1,i2,a11,urr=',ca,cb,i1,i2,a11(i1,i2,i3),urr(i1,i2,i3,c)
c          i1=i1+1
c          write(*,*) ' dsg: i1,i2,a11,urr=',i1,i2,a11(i1,i2,i3),urr(i1,i2,i3,c)

        else if( dir1.eq.0 .and. dir2.eq.1 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urs(i1+1,i2,i3,c)-a11(i1,i2,i3)*urs(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urs(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urs(i1,i2,i3,c))
                end do
              end do
            end do
          end do

        else if( dir1.eq.1 .and. dir2.eq.0 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*usr(i1,i2+1,i3,c)-a11(i1,i2,i3)*usr(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*usr(i1,i2+1,i3,c)-
     & a11(i1,i2,i3)*usr(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.1 .and. dir2.eq.1 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*uss(i1,i2+1,i3,c)-a11(i1,i2,i3)*uss(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*uss(i1,i2+1,i3,c)-
     & a11(i1,i2,i3)*uss(i1,i2,i3,c))
                end do
              end do
            end do
          end do

        end if
      end if

      return
      end


      subroutine divScalarGradFDeriv23R( nd,
     &    nd1a,nd1b,nd2a,nd2b,nd3a,nd3b,
     &    ndu1a,ndu1b,ndu2a,ndu2b,ndu3a,ndu3b,ndu4a,ndu4b, ! dimensions for u
     &    ndd1a,ndd1b,ndd2a,ndd2b,ndd3a,ndd3b,ndd4a,ndd4b, ! dimensions for deriv
     &    n1a,n1b,n2a,n2b,n3a,n3b, ca,cb,
     &    dx,   ! ********* this was changed ************
     &    u,s, deriv,
     &    a11,a22,a33, a12,a13,a21,a23,a31,a32,  ! work space
     &    derivOption, gridType, order, averagingType, dir1, dir2 )
c ===============================================================
c 2nd order, 3D, rectangular
c Conservative discretization of
c           div( s grad )
c           div( tensor Grad)
c           derivativeScalarDerivative - D_x1( s D_x2(u) )
c  
c ca,cb : assign components c=ca,..,cb (base 0)
c derivOption : 0=laplace, 1=divScalarGrad, 2=derivativeScalarDerivative
c gridType: 0=rectangular, 1=non-rectangular
c order : 2 or 4
c rsxy : not used if rectangular
c dx : grid spacing 
c a11,a22,a33 : only a11 is needed for derivOption==derivativeScalarDerivative
c ===============================================================

c      implicit none
      integer nd,
     & nd1a,nd1b,nd2a,nd2b,nd3a,nd3b,
     & ndu1a,ndu1b,ndu2a,ndu2b,ndu3a,ndu3b,ndu4a,ndu4b,
     & ndd1a,ndd1b,ndd2a,ndd2b,ndd3a,ndd3b,ndd4a,ndd4b,
     &  n1a,n1b,n2a,n2b,n3a,n3b, ca,cb,
     &  derivOption, gridType, order, averagingType, dir1, dir2

      integer arithmeticAverage,harmonicAverage
      parameter( arithmeticAverage=0,harmonicAverage=1 )
      integer laplace,divScalarGrad,derivativeScalarDerivative,
     & divTensorGrad
      parameter(laplace=0,divScalarGrad=1,derivativeScalarDerivative=2,
     & divTensorGrad=3)
      real s(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b,0:*)
      real u(ndu1a:ndu1b,ndu2a:ndu2b,ndu3a:ndu3b,ndu4a:ndu4b)
      real deriv(ndd1a:ndd1b,ndd2a:ndd2b,ndd3a:ndd3b,ndd4a:ndd4b)

      real a11(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a21(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a31(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a12(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a22(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a32(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a13(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a23(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)
      real a33(nd1a:nd1b,nd2a:nd2b,nd3a:nd3b)

      real dx(3),h22(3),h21(3)

      real factor,hh
      real urr,uss,utt,urs,usr,urt,utr,ust,uts

      integer i1,i2,i3,kd3,c,j1,j2,j3,n
      integer  m1a,m1b,m2a,m2b,m3a,m3b

c.......statement functions 
      ! Estimate D{-r}(i-1/2,j,k)
      urr(i1,i2,i3,c)=u(i1,i2,i3,c)-u(i1-1,i2,i3,c)
      ! Estimate D{-s}(i-1/2,j+1/2,k)
      urs(i1,i2,i3,c)=(u(i1-1,i2+1,i3,c)+u(i1,i2+1,i3,c)-
     &     u(i1-1,i2-1,i3,c)-u(i1,i2-1,i3,c))
      ! Estimate D{-t}(i-1/2,j,k+1/2)
      urt(i1,i2,i3,c) = (u(i1-1,i2,i3+1,c) + u(i1,i2,i3+1,c) -
     &                   u(i1-1,i2,i3-1,c) - u(i1,i2,i3-1,c))
      ! Estimate D{-r}(i+1/2,j,k-1/2)
      utr(i1,i2,i3,c) = (u(i1+1,i2,i3-1,c) + u(i1+1,i2,i3,c) -
     &                   u(i1-1,i2,i3-1,c) - u(i1-1,i2,i3,c))
      ! Estimate D{-s}(i,j+1/2,k-1/2)
      uts(i1,i2,i3,c) = (u(i1,i2+1,i3-1,c) + u(i1,i2+1,i3,c) -
     &                   u(i1,i2-1,i3-1,c) - u(i1,i2-1,i3,c))
      ! Estimate D{-t}(i,j,k-1/2)
      utt(i1,i2,i3,c) =u(i1,i2,i3,c)-u(i1,i2,i3-1,c)
      ! Estimate D{-r}(i+1/2,j-1/2,k)
      usr(i1,i2,i3,c) = (u(i1+1,i2-1,i3,c) + u(i1+1,i2,i3,c) -
     &                   u(i1-1,i2-1,i3,c) - u(i1-1,i2,i3,c))
      ! Estimate D{-s}(i,j-1/2,k)
      uss(i1,i2,i3,c) = u(i1,i2,i3,c)-u(i1,i2-1,i3,c)
      ! Estimate D{-t}(i,j-1/2,k+1/2)
      ust(i1,i2,i3,c) = (u(i1,i2-1,i3+1,c) + u(i1,i2,i3+1,c) -
     &                   u(i1,i2-1,i3-1,c) - u(i1,i2,i3-1,c))

      D0r(i1,i2,i3,c)=u(i1+1,i2,i3,c)-u(i1-1,i2,i3,c)
      D0s(i1,i2,i3,c)=u(i1,i2+1,i3,c)-u(i1,i2-1,i3,c)
      D0t(i1,i2,i3,c)=u(i1,i2,i3+1,c)-u(i1,i2,i3-1,c)

c.......end statement functions


      if( derivOption.eq.laplace )then
         write(*,*) 'ERROR: divScalarGradFDeriv23R should not be' //
     &    ' called for laplace'
         return
      end if

      kd3=nd
      do n=1,nd
        h22(n)=1./dx(n)**2
        h21(n)=.5/dx(n)
      end do


! defineA23R()
      m1a=n1a-1
      m1b=n1b+1
      m2a=n2a-1
      m2b=n2b+1
      m3a=n3a-1
      m3b=n3b+1
      if( averagingType .eq. arithmeticAverage )then
       factor=.5
       if( derivOption.eq.divScalarGrad  )then
! loopsDSG1(a11(j1,j2,j3) = factor*h22(1)*(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
         m1a=n1a
         do j3=m3a,m3b
           do j2=m2a,m2b
             do j1=m1a,m1b
               a11(j1,j2,j3)=factor*h22(1)*(s(j1,j2,j3,0)+s(j1-1,j2,j3,
     & 0))
             end do
           end do
         end do
         m1a=n1a-1
! loopsDSG2(a22(j1,j2,j3) = factor*h22(2)*(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
         m2a=n2a
         do j3=m3a,m3b
           do j2=m2a,m2b
             do j1=m1a,m1b
               a22(j1,j2,j3)=factor*h22(2)*(s(j1,j2,j3,0)+s(j1,j2-1,j3,
     & 0))
             end do
           end do
         end do
         m2a=n2a-1
! loopsDSG3(a33(j1,j2,j3) = factor*h22(3)*(s(j1,j2,j3,0)+s(j1,j2,j3-1,0)))
         m3a=n3a
         do j3=m3a,m3b
           do j2=m2a,m2b
             do j1=m1a,m1b
               a33(j1,j2,j3)=factor*h22(3)*(s(j1,j2,j3,0)+s(j1,j2,j3-1,
     & 0))
             end do
           end do
         end do
         m3a=n3a-1
       else if( derivOption.eq.divTensorGrad )then
         ! form the coefficients and average
         !   we need to worry about the end points m1a=n1a-1 *wdh* 060210
         do j3=m3a,m3b
           j3m1=max(j3-1,m3a)
         do j2=m2a,m2b
           j2m1=max(j2-1,m2a)
         do j1=m1a,m1b
           j1m1=max(j1-1,m1a)
           a11(j1,j2,j3) = .5*(s(j1,j2,j3,0)+s(j1m1,j2,j3,0))/dx(1)**2
           a21(j1,j2,j3) =     s(j1,j2,j3,1)/(4.*dx(2)*dx(1))
           a31(j1,j2,j3) =     s(j1,j2,j3,2)/(4.*dx(3)*dx(1))
           a12(j1,j2,j3) =     s(j1,j2,j3,3)/(4.*dx(1)*dx(2))
           a22(j1,j2,j3) = .5*(s(j1,j2,j3,4)+s(j1,j2m1,j3,4))/dx(2)**2
           a32(j1,j2,j3) =     s(j1,j2,j3,5)/(4.*dx(3)*dx(2))
           a13(j1,j2,j3) =     s(j1,j2,j3,6)/(4.*dx(1)*dx(3))
           a23(j1,j2,j3) =     s(j1,j2,j3,7)/(4.*dx(2)*dx(3))
           a33(j1,j2,j3) = .5*(s(j1,j2,j3,8)+s(j1,j2,j3m1,8))/dx(3)**2
         end do
         end do
         end do
       else if( derivOption.eq.derivativeScalarDerivative )then
         if( dir1.eq.dir2 )then
           hh=h22(dir1+1)
         else
           hh=h21(dir1+1)*h21(dir2+1)
         end if
         if( dir1.eq.0 )then
! loopsDSG1(a11(j1,j2,j3) = factor*hh*(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
           m1a=n1a
           do j3=m3a,m3b
             do j2=m2a,m2b
               do j1=m1a,m1b
                 a11(j1,j2,j3)=factor*hh*(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)
     & )
               end do
             end do
           end do
           m1a=n1a-1
         else if( dir1.eq.1 )then
! loopsDSG2(a11(j1,j2,j3) = factor*hh*(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
           m2a=n2a
           do j3=m3a,m3b
             do j2=m2a,m2b
               do j1=m1a,m1b
                 a11(j1,j2,j3)=factor*hh*(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)
     & )
               end do
             end do
           end do
           m2a=n2a-1
         else
! loopsDSG3(a11(j1,j2,j3) = factor*hh*(s(j1,j2,j3,0)+s(j1,j2,j3-1,0)))
           m3a=n3a
           do j3=m3a,m3b
             do j2=m2a,m2b
               do j1=m1a,m1b
                 a11(j1,j2,j3)=factor*hh*(s(j1,j2,j3,0)+s(j1,j2,j3-1,0)
     & )
               end do
             end do
           end do
           m3a=n3a-1
         end if
       else
         stop 3329
       end if
      else
c  Harmonic average
        factor=2.
        if( derivOption.eq.divScalarGrad  )then
          ! should be worry about division by zero?
! loopsDSG1(a11(j1,j2,j3) =s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*h22(1)*factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
          m1a=n1a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*h22(1)*
     & factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0))
              end do
            end do
          end do
          m1a=n1a-1
! loopsDSG2(a22(j1,j2,j3) =s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*h22(2)*factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
          m2a=n2a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a22(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*h22(2)*
     & factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0))
              end do
            end do
          end do
          m2a=n2a-1
! loopsDSG3(a33(j1,j2,j3) =s(j1,j2,j3,0)*s(j1,j2,j3-1,0)*h22(3)*factor/(s(j1,j2,j3,0)+s(j1,j2,j3-1,0)))
          m3a=n3a
          do j3=m3a,m3b
            do j2=m2a,m2b
              do j1=m1a,m1b
                a33(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2,j3-1,0)*h22(3)*
     & factor/(s(j1,j2,j3,0)+s(j1,j2,j3-1,0))
              end do
            end do
          end do
          m3a=n3a-1
        else if( derivOption.eq.divTensorGrad )then
          stop 3388
        else if( derivOption.eq.derivativeScalarDerivative )then
          if( dir1.eq.dir2 )then
            hh=h22(dir1+1)
          else
            hh=h21(dir1+1)*h21(dir2+1)
          end if
          if( dir1.eq.0 )then
! loopsDSG1(a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*hh*factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0)))
            m1a=n1a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1-1,j2,j3,0)*hh*
     & factor/(s(j1,j2,j3,0)+s(j1-1,j2,j3,0))
                end do
              end do
            end do
            m1a=n1a-1
          else if( dir1.eq.1 )then
! loopsDSG2(a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*hh*factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0)))
            m2a=n2a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2-1,j3,0)*hh*
     & factor/(s(j1,j2,j3,0)+s(j1,j2-1,j3,0))
                end do
              end do
            end do
            m2a=n2a-1
          else
! loopsDSG3(a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2,j3-1,0)*hh*factor/(s(j1,j2,j3,0)+s(j1,j2,j3-1,0)))
            m3a=n3a
            do j3=m3a,m3b
              do j2=m2a,m2b
                do j1=m1a,m1b
                  a11(j1,j2,j3)=s(j1,j2,j3,0)*s(j1,j2,j3-1,0)*hh*
     & factor/(s(j1,j2,j3,0)+s(j1,j2,j3-1,0))
                end do
              end do
            end do
            m3a=n3a-1
          end if
        else
          stop 3429
        end if
      end if

c      Evaluate the derivative
      if( derivOption.eq.divScalarGrad )then
! loopsDSG(deriv(i1,i2,i3,c)=(  (a11(i1+1,i2  ,i3  )*urr(i1+1,i2  ,i3  ,c) -  a11(i1,i2,i3)*urr(i1,i2,i3,c))+  (a22(i1  ,i2+1,i3  )*uss(i1  ,i2+1,i3  ,c) -   a22(i1,i2,i3)*uss(i1,i2,i3,c))+  (a33(i1  ,i2  ,i3+1)*utt(i1  ,i2  ,i3+1,c) -   a33(i1,i2,i3)*utt(i1,i2,i3,c)) ))
        do c=ca,cb
          do i3=n3a,n3b
            do i2=n2a,n2b
              do i1=n1a,n1b
                deriv(i1,i2,i3,c)=((a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urr(i1,i2,i3,c))+(a22(i1,i2+1,i3)*uss(i1,i2+1,i3,
     & c)-a22(i1,i2,i3)*uss(i1,i2,i3,c))+(a33(i1,i2,i3+1)*utt(i1,i2,
     & i3+1,c)-a33(i1,i2,i3)*utt(i1,i2,i3,c)))
              end do
            end do
          end do
        end do
      else if( derivOption.eq.divTensorGrad )then
c       ** here is the new symmetric formula ***
        do c=ca,cb
          do i3=n3a,n3b
            do i2=n2a,n2b
              do i1=n1a,n1b
              deriv(i1,i2,i3,c)=
     &         (
     & (a11(i1+1,i2  ,i3  )*urr(i1+1,i2  ,i3  ,c) - a11(i1,i2,i3)*urr(
     & i1  ,i2  ,i3  ,c))+
     & (a22(i1  ,i2+1,i3  )*uss(i1  ,i2+1,i3  ,c) - a22(i1,i2,i3)*uss(
     & i1  ,i2  ,i3  ,c))+
     & (a33(i1  ,i2  ,i3+1)*utt(i1  ,i2  ,i3+1,c) - a33(i1,i2,i3)*utt(
     & i1  ,i2  ,i3  ,c))+
     & (a21(i1  ,i2+1,i3  )*D0r(i1  ,i2+1,i3  ,c) - a21(i1,i2-1,i3)*
     & D0r(i1  ,i2-1,i3  ,c) +
     & a12(i1+1,i2  ,i3  )*D0s(i1+1,i2  ,i3  ,c) - a12(i1-1,i2,i3)*
     & D0s(i1-1,i2  ,i3  ,c))+
     & (a31(i1  ,i2  ,i3+1)*D0r(i1  ,i2  ,i3+1,c) - a31(i1,i2,i3-1)*
     & D0r(i1  ,i2  ,i3-1,c) +
     & a13(i1+1,i2  ,i3  )*D0t(i1+1,i2  ,i3  ,c) - a13(i1-1,i2,i3)*
     & D0t(i1-1,i2  ,i3  ,c))+
     & (a32(i1  ,i2  ,i3+1)*D0s(i1  ,i2  ,i3+1,c) - a32(i1,i2,i3-1)*
     & D0s(i1  ,i2  ,i3-1,c) +
     & a23(i1  ,i2+1,i3  )*D0t(i1  ,i2+1,i3  ,c) - a23(i1,i2-1,i3)*
     & D0t(i1  ,i2-1,i3  ,c))
     &        )
              end do
            end do
          end do
        end do
      else
c       derivative scalar derivative
        if( dir1.eq.0 .and. dir2.eq.0 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-a11(i1,i2,i3)*urr(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urr(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urr(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.0 .and. dir2.eq.1 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urs(i1+1,i2,i3,c)-a11(i1,i2,i3)*urs(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urs(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urs(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.0 .and. dir2.eq.2 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urt(i1+1,i2,i3,c)-a11(i1,i2,i3)*urt(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1+1,i2,i3)*urt(i1+1,i2,i3,c)-
     & a11(i1,i2,i3)*urt(i1,i2,i3,c))
                end do
              end do
            end do
          end do

        else if( dir1.eq.1 .and. dir2.eq.0 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*usr(i1,i2+1,i3,c)-a11(i1,i2,i3)*usr(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*usr(i1,i2+1,i3,c)-
     & a11(i1,i2,i3)*usr(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.1 .and. dir2.eq.1 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*uss(i1,i2+1,i3,c)-a11(i1,i2,i3)*uss(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*uss(i1,i2+1,i3,c)-
     & a11(i1,i2,i3)*uss(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.1 .and. dir2.eq.2 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*ust(i1,i2+1,i3,c)-a11(i1,i2,i3)*ust(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2+1,i3)*ust(i1,i2+1,i3,c)-
     & a11(i1,i2,i3)*ust(i1,i2,i3,c))
                end do
              end do
            end do
          end do

        else if( dir1.eq.2 .and. dir2.eq.0 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2,i3+1)*utr(i1,i2,i3+1,c)-a11(i1,i2,i3)*utr(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2,i3+1)*utr(i1,i2,i3+1,c)-
     & a11(i1,i2,i3)*utr(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.2 .and. dir2.eq.1 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2,i3+1)*uts(i1,i2,i3+1,c)-a11(i1,i2,i3)*uts(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2,i3+1)*uts(i1,i2,i3+1,c)-
     & a11(i1,i2,i3)*uts(i1,i2,i3,c))
                end do
              end do
            end do
          end do
        else if( dir1.eq.2 .and. dir2.eq.2 )then
! loopsDSG(deriv(i1,i2,i3,c)=(a11(i1,i2,i3+1)*utt(i1,i2,i3+1,c)-a11(i1,i2,i3)*utt(i1,i2,i3,c)))
          do c=ca,cb
            do i3=n3a,n3b
              do i2=n2a,n2b
                do i1=n1a,n1b
                  deriv(i1,i2,i3,c)=(a11(i1,i2,i3+1)*utt(i1,i2,i3+1,c)-
     & a11(i1,i2,i3)*utt(i1,i2,i3,c))
                end do
              end do
            end do
          end do

        end if
      end if

      return
      end

