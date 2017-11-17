c Define statement functions for difference approximations of order 4 
c Thsi file was generated by op/src/makeIncludeNew.p  
c Arguments: u,rx,dr,dx: names for the grid function, jacobian, unit square spacing and rectangular grid spacing
c To include derivatives of rx use OPTION=RX
#beginMacro defineDifferenceNewOrder4Components0(u,rx,dr,dx,OPTION)

#If #OPTION == "RX"
dr ## 14(kd) = 1./(12.*dr(kd))
dr ## 24(kd) = 1./(12.*dr(kd)**2)
#End

u ## r4(i1,i2,i3)=(8.*(u(i1+1,i2,i3)-u(i1-1,i2,i3))-(u(i1+2,i2,i3)-u(i1-2,i2,i3)))*dr ## 14(0)
u ## s4(i1,i2,i3)=(8.*(u(i1,i2+1,i3)-u(i1,i2-1,i3))-(u(i1,i2+2,i3)-u(i1,i2-2,i3)))*dr ## 14(1)
u ## t4(i1,i2,i3)=(8.*(u(i1,i2,i3+1)-u(i1,i2,i3-1))-(u(i1,i2,i3+2)-u(i1,i2,i3-2)))*dr ## 14(2)

u ## rr4(i1,i2,i3)=(-30.*u(i1,i2,i3)+16.*(u(i1+1,i2,i3)+u(i1-1,i2,i3))-(u(i1+2,i2,i3)+u(i1-2,i2,i3)) )*dr ## 24(0)
u ## ss4(i1,i2,i3)=(-30.*u(i1,i2,i3)+16.*(u(i1,i2+1,i3)+u(i1,i2-1,i3))-(u(i1,i2+2,i3)+u(i1,i2-2,i3)) )*dr ## 24(1)
u ## tt4(i1,i2,i3)=(-30.*u(i1,i2,i3)+16.*(u(i1,i2,i3+1)+u(i1,i2,i3-1))-(u(i1,i2,i3+2)+u(i1,i2,i3-2)) )*dr ## 24(2)
u ## rs4(i1,i2,i3)=(8.*(u ## r4(i1,i2+1,i3)-u ## r4(i1,i2-1,i3))-(u ## r4(i1,i2+2,i3)-u ## r4(i1,i2-2,i3)))*dr ## 14(1)
u ## rt4(i1,i2,i3)=(8.*(u ## r4(i1,i2,i3+1)-u ## r4(i1,i2,i3-1))-(u ## r4(i1,i2,i3+2)-u ## r4(i1,i2,i3-2)))*dr ## 14(2)
u ## st4(i1,i2,i3)=(8.*(u ## s4(i1,i2,i3+1)-u ## s4(i1,i2,i3-1))-(u ## s4(i1,i2,i3+2)-u ## s4(i1,i2,i3-2)))*dr ## 14(2)

#If #OPTION == "RX"
rx ##r4(i1,i2,i3,m,n)=(8.*(rx ##(i1+1,i2,i3,m,n)-rx ##(i1-1,i2,i3,m,n))-(rx ##(i1+2,i2,i3,m,n)-rx ##(i1-2,i2,i3,m,n)))*dr ## 14(0)
rx ##s4(i1,i2,i3,m,n)=(8.*(rx ##(i1,i2+1,i3,m,n)-rx ##(i1,i2-1,i3,m,n))-(rx ##(i1,i2+2,i3,m,n)-rx ##(i1,i2-2,i3,m,n)))*dr ## 14(1)
rx ##t4(i1,i2,i3,m,n)=(8.*(rx ##(i1,i2,i3+1,m,n)-rx ##(i1,i2,i3-1,m,n))-(rx ##(i1,i2,i3+2,m,n)-rx ##(i1,i2,i3-2,m,n)))*dr ## 14(2)
#End

u ## x41(i1,i2,i3)= rx(i1,i2,i3,0,0)*u ## r4(i1,i2,i3)
u ## y41(i1,i2,i3)=0
u ## z41(i1,i2,i3)=0

u ## x42(i1,i2,i3)= rx(i1,i2,i3,0,0)*u ## r4(i1,i2,i3)+rx(i1,i2,i3,1,0)*u ## s4(i1,i2,i3)
u ## y42(i1,i2,i3)= rx(i1,i2,i3,0,1)*u ## r4(i1,i2,i3)+rx(i1,i2,i3,1,1)*u ## s4(i1,i2,i3)
u ## z42(i1,i2,i3)=0
u ## x43(i1,i2,i3)=rx(i1,i2,i3,0,0)*u ## r4(i1,i2,i3)+rx(i1,i2,i3,1,0)*u ## s4(i1,i2,i3)+rx(i1,i2,i3,2,0)*u ## t4(i1,i2,i3)
u ## y43(i1,i2,i3)=rx(i1,i2,i3,0,1)*u ## r4(i1,i2,i3)+rx(i1,i2,i3,1,1)*u ## s4(i1,i2,i3)+rx(i1,i2,i3,2,1)*u ## t4(i1,i2,i3)
u ## z43(i1,i2,i3)=rx(i1,i2,i3,0,2)*u ## r4(i1,i2,i3)+rx(i1,i2,i3,1,2)*u ## s4(i1,i2,i3)+rx(i1,i2,i3,2,2)*u ## t4(i1,i2,i3)

#If #OPTION == "RX"
rx ## x41(i1,i2,i3,m,n)= rx(i1,i2,i3,0,0)*rx ##r4(i1,i2,i3,m,n)
rx ##x42(i1,i2,i3,m,n)= rx(i1,i2,i3,0,0)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,0)*rx ##s4(i1,i2,i3,m,n)
rx ##y42(i1,i2,i3,m,n)= rx(i1,i2,i3,0,1)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,1)*rx ##s4(i1,i2,i3,m,n)
rx ##x43(i1,i2,i3,m,n)=rx(i1,i2,i3,0,0)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,0)*rx ##s4(i1,i2,i3,m,n)+rx(i1,i2,i3,2,0)*rx ##t4(i1,i2,i3,m,n)
rx ##y43(i1,i2,i3,m,n)=rx(i1,i2,i3,0,1)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,1)*rx ##s4(i1,i2,i3,m,n)+rx(i1,i2,i3,2,1)*rx ##t4(i1,i2,i3,m,n)
rx ##z43(i1,i2,i3,m,n)=rx(i1,i2,i3,0,2)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,2)*rx ##s4(i1,i2,i3,m,n)+rx(i1,i2,i3,2,2)*rx ##t4(i1,i2,i3,m,n)
#End

u ## xx41(i1,i2,i3)=(rx(i1,i2,i3,0,0)**2)*u ## rr4(i1,i2,i3)+(rx ## x4 ## 2(i1,i2,i3,0,0))*u ## r4(i1,i2,i3)
u ## yy41(i1,i2,i3)=0
u ## xy41(i1,i2,i3)=0
u ## xz41(i1,i2,i3)=0
u ## yz41(i1,i2,i3)=0
u ## zz41(i1,i2,i3)=0
u ## laplacian41(i1,i2,i3)=u ## xx41(i1,i2,i3)
u ## xx42(i1,i2,i3)=(rx(i1,i2,i3,0,0)**2)*u ## rr4(i1,i2,i3)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3)+(rx(i1,i2,i3,1,0)**2)*u ## ss4(i1,i2,i3)+(rx ## x4 ## 2(i1,i2,i3,0,0))*u ## r4(i1,i2,i3)+(rx ## x4 ## 2(i1,i2,i3,1,0))*u ## s4(i1,i2,i3)
u ## yy42(i1,i2,i3)=(rx(i1,i2,i3,0,1)**2)*u ## rr4(i1,i2,i3)+2.*(rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1))*u ## rs4(i1,i2,i3)+(rx(i1,i2,i3,1,1)**2)*u ## ss4(i1,i2,i3)+(rx ## y4 ## 2(i1,i2,i3,0,1))*u ## r4(i1,i2,i3)+(rx ## y4 ## 2(i1,i2,i3,1,1))*u ## s4(i1,i2,i3)
u ## xy42(i1,i2,i3)=rx(i1,i2,i3,0,0)*rx(i1,i2,i3,0,1)*u ## rr4(i1,i2,i3)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,1)+rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3)+rx(i1,i2,i3,1,0)*rx(i1,i2,i3,1,1)*u ## ss4(i1,i2,i3)+rx ## x4 ## 2(i1,i2,i3,0,1)*u ## r4(i1,i2,i3)+rx ## x4 ## 2(i1,i2,i3,1,1)*u ## s4(i1,i2,i3)
u ## xz42(i1,i2,i3)=0
u ## yz42(i1,i2,i3)=0
u ## zz42(i1,i2,i3)=0
u ## laplacian42(i1,i2,i3)=(rx(i1,i2,i3,0,0)**2+rx(i1,i2,i3,0,1)**2)*u ## rr4(i1,i2,i3)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0)+ rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1))*u ## rs4(i1,i2,i3)+(rx(i1,i2,i3,1,0)**2+rx(i1,i2,i3,1,1)**2)*u ## ss4(i1,i2,i3)+(rx ## x4 ## 2(i1,i2,i3,0,0)+rx ## y4 ## 2(i1,i2,i3,0,1))*u ## r4(i1,i2,i3)+(rx ## x4 ## 2(i1,i2,i3,1,0)+rx ## y4 ## 2(i1,i2,i3,1,1))*u ## s4(i1,i2,i3)
u ## xx43(i1,i2,i3)=rx(i1,i2,i3,0,0)**2*u ## rr4(i1,i2,i3)+rx(i1,i2,i3,1,0)**2*u ## ss4(i1,i2,i3)+rx(i1,i2,i3,2,0)**2*u ## tt4(i1,i2,i3)+2.*rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0)*u ## rs4(i1,i2,i3)+2.*rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,0)*u ## rt4(i1,i2,i3)+2.*rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,0)*u ## st4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,0,0)*u ## r4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,1,0)*u ## s4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,2,0)*u ## t4(i1,i2,i3)
u ## yy43(i1,i2,i3)=rx(i1,i2,i3,0,1)**2*u ## rr4(i1,i2,i3)+rx(i1,i2,i3,1,1)**2*u ## ss4(i1,i2,i3)+rx(i1,i2,i3,2,1)**2*u ## tt4(i1,i2,i3)+2.*rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1)*u ## rs4(i1,i2,i3)+2.*rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,1)*u ## rt4(i1,i2,i3)+2.*rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,1)*u ## st4(i1,i2,i3)+rx ## y4 ## 3(i1,i2,i3,0,1)*u ## r4(i1,i2,i3)+rx ## y4 ## 3(i1,i2,i3,1,1)*u ## s4(i1,i2,i3)+rx ## y4 ## 3(i1,i2,i3,2,1)*u ## t4(i1,i2,i3)
u ## zz43(i1,i2,i3)=rx(i1,i2,i3,0,2)**2*u ## rr4(i1,i2,i3)+rx(i1,i2,i3,1,2)**2*u ## ss4(i1,i2,i3)+rx(i1,i2,i3,2,2)**2*u ## tt4(i1,i2,i3)+2.*rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,2)*u ## rs4(i1,i2,i3)+2.*rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,2)*u ## rt4(i1,i2,i3)+2.*rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,2)*u ## st4(i1,i2,i3)+rx ## z4 ## 3(i1,i2,i3,0,2)*u ## r4(i1,i2,i3)+rx ## z4 ## 3(i1,i2,i3,1,2)*u ## s4(i1,i2,i3)+rx ## z4 ## 3(i1,i2,i3,2,2)*u ## t4(i1,i2,i3)
u ## xy43(i1,i2,i3)=rx(i1,i2,i3,0,0)*rx(i1,i2,i3,0,1)*u ## rr4(i1,i2,i3)+rx(i1,i2,i3,1,0)*rx(i1,i2,i3,1,1)*u ## ss4(i1,i2,i3)+rx(i1,i2,i3,2,0)*rx(i1,i2,i3,2,1)*u ## tt4(i1,i2,i3)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,1)+rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,0))*u ## rt4(i1,i2,i3)+(rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,0))*u ## st4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,0,1)*u ## r4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,1,1)*u ## s4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,2,1)*u ## t4(i1,i2,i3)
u ## xz43(i1,i2,i3)=rx(i1,i2,i3,0,0)*rx(i1,i2,i3,0,2)*u ## rr4(i1,i2,i3)+rx(i1,i2,i3,1,0)*rx(i1,i2,i3,1,2)*u ## ss4(i1,i2,i3)+rx(i1,i2,i3,2,0)*rx(i1,i2,i3,2,2)*u ## tt4(i1,i2,i3)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,0))*u ## rt4(i1,i2,i3)+(rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,0))*u ## st4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,0,2)*u ## r4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,1,2)*u ## s4(i1,i2,i3)+rx ## x4 ## 3(i1,i2,i3,2,2)*u ## t4(i1,i2,i3)
u ## yz43(i1,i2,i3)=rx(i1,i2,i3,0,1)*rx(i1,i2,i3,0,2)*u ## rr4(i1,i2,i3)+rx(i1,i2,i3,1,1)*rx(i1,i2,i3,1,2)*u ## ss4(i1,i2,i3)+rx(i1,i2,i3,2,1)*rx(i1,i2,i3,2,2)*u ## tt4(i1,i2,i3)+(rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,1))*u ## rs4(i1,i2,i3)+(rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,1))*u ## rt4(i1,i2,i3)+(rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,1))*u ## st4(i1,i2,i3)+rx ## y4 ## 3(i1,i2,i3,0,2)*u ## r4(i1,i2,i3)+rx ## y4 ## 3(i1,i2,i3,1,2)*u ## s4(i1,i2,i3)+rx ## y4 ## 3(i1,i2,i3,2,2)*u ## t4(i1,i2,i3)
u ## laplacian43(i1,i2,i3)=(rx(i1,i2,i3,0,0)**2+rx(i1,i2,i3,0,1)**2+rx(i1,i2,i3,0,2)**2)*u ## rr4(i1,i2,i3)+(rx(i1,i2,i3,1,0)**2+rx(i1,i2,i3,1,1)**2+rx(i1,i2,i3,1,2)**2)*u ## ss4(i1,i2,i3)+(rx(i1,i2,i3,2,0)**2+rx(i1,i2,i3,2,1)**2+rx(i1,i2,i3,2,2)**2)*u ## tt4(i1,i2,i3)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0)+ rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,2))*u ## rs4(i1,i2,i3)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,0)+ rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,2))*u ## rt4(i1,i2,i3)+2.*(rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,0)+ rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,2))*u ## st4(i1,i2,i3)+(rx ## x4 ## 3(i1,i2,i3,0,0)+rx ## y4 ## 3(i1,i2,i3,0,1)+rx ## z4 ## 3(i1,i2,i3,0,2))*u ## r4(i1,i2,i3)+(rx ## x4 ## 3(i1,i2,i3,1,0)+rx ## y4 ## 3(i1,i2,i3,1,1)+rx ## z4 ## 3(i1,i2,i3,1,2))*u ## s4(i1,i2,i3)+(rx ## x4 ## 3(i1,i2,i3,2,0)+rx ## y4 ## 3(i1,i2,i3,2,1)+rx ## z4 ## 3(i1,i2,i3,2,2))*u ## t4(i1,i2,i3)
c============================================================================================
c Define derivatives for a rectangular grid
c
c============================================================================================
#If #OPTION == "RX"
dx ## 41(kd) = 1./(12.*dx(kd))
dx ## 42(kd) = 1./(12.*dx(kd)**2)
#End
u ## x43r(i1,i2,i3)=(8.*(u(i1+1,i2,i3)-u(i1-1,i2,i3))-(u(i1+2,i2,i3)-u(i1-2,i2,i3)))*dx ## 41(0)
u ## y43r(i1,i2,i3)=(8.*(u(i1,i2+1,i3)-u(i1,i2-1,i3))-(u(i1,i2+2,i3)-u(i1,i2-2,i3)))*dx ## 41(1)
u ## z43r(i1,i2,i3)=(8.*(u(i1,i2,i3+1)-u(i1,i2,i3-1))-(u(i1,i2,i3+2)-u(i1,i2,i3-2)))*dx ## 41(2)
u ## xx43r(i1,i2,i3)=( -30.*u(i1,i2,i3)+16.*(u(i1+1,i2,i3)+u(i1-1,i2,i3))-(u(i1+2,i2,i3)+u(i1-2,i2,i3)) )*dx ## 42(0) 
u ## yy43r(i1,i2,i3)=( -30.*u(i1,i2,i3)+16.*(u(i1,i2+1,i3)+u(i1,i2-1,i3))-(u(i1,i2+2,i3)+u(i1,i2-2,i3)) )*dx ## 42(1) 
u ## zz43r(i1,i2,i3)=( -30.*u(i1,i2,i3)+16.*(u(i1,i2,i3+1)+u(i1,i2,i3-1))-(u(i1,i2,i3+2)+u(i1,i2,i3-2)) )*dx ## 42(2)
u ## xy43r(i1,i2,i3)=( (u(i1+2,i2+2,i3)-u(i1-2,i2+2,i3)- u(i1+2,i2-2,i3)+u(i1-2,i2-2,i3)) +8.*(u(i1-1,i2+2,i3)-u(i1-1,i2-2,i3)-u(i1+1,i2+2,i3)+u(i1+1,i2-2,i3) +u(i1+2,i2-1,i3)-u(i1-2,i2-1,i3)-u(i1+2,i2+1,i3)+u(i1-2,i2+1,i3))+64.*(u(i1+1,i2+1,i3)-u(i1-1,i2+1,i3)- u(i1+1,i2-1,i3)+u(i1-1,i2-1,i3)))*(dx ## 41(0)*dx ## 41(1))
u ## xz43r(i1,i2,i3)=( (u(i1+2,i2,i3+2)-u(i1-2,i2,i3+2)-u(i1+2,i2,i3-2)+u(i1-2,i2,i3-2)) +8.*(u(i1-1,i2,i3+2)-u(i1-1,i2,i3-2)-u(i1+1,i2,i3+2)+u(i1+1,i2,i3-2) +u(i1+2,i2,i3-1)-u(i1-2,i2,i3-1)- u(i1+2,i2,i3+1)+u(i1-2,i2,i3+1)) +64.*(u(i1+1,i2,i3+1)-u(i1-1,i2,i3+1)-u(i1+1,i2,i3-1)+u(i1-1,i2,i3-1)) )*(dx ## 41(0)*dx ## 41(2))
u ## yz43r(i1,i2,i3)=( (u(i1,i2+2,i3+2)-u(i1,i2-2,i3+2)-u(i1,i2+2,i3-2)+u(i1,i2-2,i3-2)) +8.*(u(i1,i2-1,i3+2)-u(i1,i2-1,i3-2)-u(i1,i2+1,i3+2)+u(i1,i2+1,i3-2) +u(i1,i2+2,i3-1)-u(i1,i2-2,i3-1)-u(i1,i2+2,i3+1)+u(i1,i2-2,i3+1)) +64.*(u(i1,i2+1,i3+1)-u(i1,i2-1,i3+1)-u(i1,i2+1,i3-1)+u(i1,i2-1,i3-1)) )*(dx ## 41(1)*dx ## 41(2))
u ## x41r(i1,i2,i3)= u ## x43r(i1,i2,i3)
u ## y41r(i1,i2,i3)= u ## y43r(i1,i2,i3)
u ## z41r(i1,i2,i3)= u ## z43r(i1,i2,i3)
u ## xx41r(i1,i2,i3)= u ## xx43r(i1,i2,i3)
u ## yy41r(i1,i2,i3)= u ## yy43r(i1,i2,i3)
u ## zz41r(i1,i2,i3)= u ## zz43r(i1,i2,i3)
u ## xy41r(i1,i2,i3)= u ## xy43r(i1,i2,i3)
u ## xz41r(i1,i2,i3)= u ## xz43r(i1,i2,i3)
u ## yz41r(i1,i2,i3)= u ## yz43r(i1,i2,i3)
u ## laplacian41r(i1,i2,i3)=u ## xx43r(i1,i2,i3)
u ## x42r(i1,i2,i3)= u ## x43r(i1,i2,i3)
u ## y42r(i1,i2,i3)= u ## y43r(i1,i2,i3)
u ## z42r(i1,i2,i3)= u ## z43r(i1,i2,i3)
u ## xx42r(i1,i2,i3)= u ## xx43r(i1,i2,i3)
u ## yy42r(i1,i2,i3)= u ## yy43r(i1,i2,i3)
u ## zz42r(i1,i2,i3)= u ## zz43r(i1,i2,i3)
u ## xy42r(i1,i2,i3)= u ## xy43r(i1,i2,i3)
u ## xz42r(i1,i2,i3)= u ## xz43r(i1,i2,i3)
u ## yz42r(i1,i2,i3)= u ## yz43r(i1,i2,i3)
u ## laplacian42r(i1,i2,i3)=u ## xx43r(i1,i2,i3)+u ## yy43r(i1,i2,i3)
u ## laplacian43r(i1,i2,i3)=u ## xx43r(i1,i2,i3)+u ## yy43r(i1,i2,i3)+u ## zz43r(i1,i2,i3)
#endMacro
c Arguments: u,rx,dr,dx: names for the grid function, jacobian, unit square spacing and rectangular grid spacing
c To include derivatives of rx use OPTION=RX
#beginMacro defineDifferenceNewOrder4Components1(u,rx,dr,dx,OPTION)

#If #OPTION == "RX"
dr ## 14(kd) = 1./(12.*dr(kd))
dr ## 24(kd) = 1./(12.*dr(kd)**2)
#End

u ## r4(i1,i2,i3,kd)=(8.*(u(i1+1,i2,i3,kd)-u(i1-1,i2,i3,kd))-(u(i1+2,i2,i3,kd)-u(i1-2,i2,i3,kd)))*dr ## 14(0)
u ## s4(i1,i2,i3,kd)=(8.*(u(i1,i2+1,i3,kd)-u(i1,i2-1,i3,kd))-(u(i1,i2+2,i3,kd)-u(i1,i2-2,i3,kd)))*dr ## 14(1)
u ## t4(i1,i2,i3,kd)=(8.*(u(i1,i2,i3+1,kd)-u(i1,i2,i3-1,kd))-(u(i1,i2,i3+2,kd)-u(i1,i2,i3-2,kd)))*dr ## 14(2)

u ## rr4(i1,i2,i3,kd)=(-30.*u(i1,i2,i3,kd)+16.*(u(i1+1,i2,i3,kd)+u(i1-1,i2,i3,kd))-(u(i1+2,i2,i3,kd)+u(i1-2,i2,i3,kd)) )*dr ## 24(0)
u ## ss4(i1,i2,i3,kd)=(-30.*u(i1,i2,i3,kd)+16.*(u(i1,i2+1,i3,kd)+u(i1,i2-1,i3,kd))-(u(i1,i2+2,i3,kd)+u(i1,i2-2,i3,kd)) )*dr ## 24(1)
u ## tt4(i1,i2,i3,kd)=(-30.*u(i1,i2,i3,kd)+16.*(u(i1,i2,i3+1,kd)+u(i1,i2,i3-1,kd))-(u(i1,i2,i3+2,kd)+u(i1,i2,i3-2,kd)) )*dr ## 24(2)
u ## rs4(i1,i2,i3,kd)=(8.*(u ## r4(i1,i2+1,i3,kd)-u ## r4(i1,i2-1,i3,kd))-(u ## r4(i1,i2+2,i3,kd)-u ## r4(i1,i2-2,i3,kd)))*dr ## 14(1)
u ## rt4(i1,i2,i3,kd)=(8.*(u ## r4(i1,i2,i3+1,kd)-u ## r4(i1,i2,i3-1,kd))-(u ## r4(i1,i2,i3+2,kd)-u ## r4(i1,i2,i3-2,kd)))*dr ## 14(2)
u ## st4(i1,i2,i3,kd)=(8.*(u ## s4(i1,i2,i3+1,kd)-u ## s4(i1,i2,i3-1,kd))-(u ## s4(i1,i2,i3+2,kd)-u ## s4(i1,i2,i3-2,kd)))*dr ## 14(2)

#If #OPTION == "RX"
rx ##r4(i1,i2,i3,m,n)=(8.*(rx ##(i1+1,i2,i3,m,n)-rx ##(i1-1,i2,i3,m,n))-(rx ##(i1+2,i2,i3,m,n)-rx ##(i1-2,i2,i3,m,n)))*dr ## 14(0)
rx ##s4(i1,i2,i3,m,n)=(8.*(rx ##(i1,i2+1,i3,m,n)-rx ##(i1,i2-1,i3,m,n))-(rx ##(i1,i2+2,i3,m,n)-rx ##(i1,i2-2,i3,m,n)))*dr ## 14(1)
rx ##t4(i1,i2,i3,m,n)=(8.*(rx ##(i1,i2,i3+1,m,n)-rx ##(i1,i2,i3-1,m,n))-(rx ##(i1,i2,i3+2,m,n)-rx ##(i1,i2,i3-2,m,n)))*dr ## 14(2)
#End

u ## x41(i1,i2,i3,kd)= rx(i1,i2,i3,0,0)*u ## r4(i1,i2,i3,kd)
u ## y41(i1,i2,i3,kd)=0
u ## z41(i1,i2,i3,kd)=0

u ## x42(i1,i2,i3,kd)= rx(i1,i2,i3,0,0)*u ## r4(i1,i2,i3,kd)+rx(i1,i2,i3,1,0)*u ## s4(i1,i2,i3,kd)
u ## y42(i1,i2,i3,kd)= rx(i1,i2,i3,0,1)*u ## r4(i1,i2,i3,kd)+rx(i1,i2,i3,1,1)*u ## s4(i1,i2,i3,kd)
u ## z42(i1,i2,i3,kd)=0
u ## x43(i1,i2,i3,kd)=rx(i1,i2,i3,0,0)*u ## r4(i1,i2,i3,kd)+rx(i1,i2,i3,1,0)*u ## s4(i1,i2,i3,kd)+rx(i1,i2,i3,2,0)*u ## t4(i1,i2,i3,kd)
u ## y43(i1,i2,i3,kd)=rx(i1,i2,i3,0,1)*u ## r4(i1,i2,i3,kd)+rx(i1,i2,i3,1,1)*u ## s4(i1,i2,i3,kd)+rx(i1,i2,i3,2,1)*u ## t4(i1,i2,i3,kd)
u ## z43(i1,i2,i3,kd)=rx(i1,i2,i3,0,2)*u ## r4(i1,i2,i3,kd)+rx(i1,i2,i3,1,2)*u ## s4(i1,i2,i3,kd)+rx(i1,i2,i3,2,2)*u ## t4(i1,i2,i3,kd)

#If #OPTION == "RX"
rx ## x41(i1,i2,i3,m,n)= rx(i1,i2,i3,0,0)*rx ##r4(i1,i2,i3,m,n)
rx ##x42(i1,i2,i3,m,n)= rx(i1,i2,i3,0,0)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,0)*rx ##s4(i1,i2,i3,m,n)
rx ##y42(i1,i2,i3,m,n)= rx(i1,i2,i3,0,1)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,1)*rx ##s4(i1,i2,i3,m,n)
rx ##x43(i1,i2,i3,m,n)=rx(i1,i2,i3,0,0)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,0)*rx ##s4(i1,i2,i3,m,n)+rx(i1,i2,i3,2,0)*rx ##t4(i1,i2,i3,m,n)
rx ##y43(i1,i2,i3,m,n)=rx(i1,i2,i3,0,1)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,1)*rx ##s4(i1,i2,i3,m,n)+rx(i1,i2,i3,2,1)*rx ##t4(i1,i2,i3,m,n)
rx ##z43(i1,i2,i3,m,n)=rx(i1,i2,i3,0,2)*rx ##r4(i1,i2,i3,m,n)+rx(i1,i2,i3,1,2)*rx ##s4(i1,i2,i3,m,n)+rx(i1,i2,i3,2,2)*rx ##t4(i1,i2,i3,m,n)
#End

u ## xx41(i1,i2,i3,kd)=(rx(i1,i2,i3,0,0)**2)*u ## rr4(i1,i2,i3,kd)+(rx ## x4 ## 2(i1,i2,i3,0,0))*u ## r4(i1,i2,i3,kd)
u ## yy41(i1,i2,i3,kd)=0
u ## xy41(i1,i2,i3,kd)=0
u ## xz41(i1,i2,i3,kd)=0
u ## yz41(i1,i2,i3,kd)=0
u ## zz41(i1,i2,i3,kd)=0
u ## laplacian41(i1,i2,i3,kd)=u ## xx41(i1,i2,i3,kd)
u ## xx42(i1,i2,i3,kd)=(rx(i1,i2,i3,0,0)**2)*u ## rr4(i1,i2,i3,kd)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,0)**2)*u ## ss4(i1,i2,i3,kd)+(rx ## x4 ## 2(i1,i2,i3,0,0))*u ## r4(i1,i2,i3,kd)+(rx ## x4 ## 2(i1,i2,i3,1,0))*u ## s4(i1,i2,i3,kd)
u ## yy42(i1,i2,i3,kd)=(rx(i1,i2,i3,0,1)**2)*u ## rr4(i1,i2,i3,kd)+2.*(rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1))*u ## rs4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,1)**2)*u ## ss4(i1,i2,i3,kd)+(rx ## y4 ## 2(i1,i2,i3,0,1))*u ## r4(i1,i2,i3,kd)+(rx ## y4 ## 2(i1,i2,i3,1,1))*u ## s4(i1,i2,i3,kd)
u ## xy42(i1,i2,i3,kd)=rx(i1,i2,i3,0,0)*rx(i1,i2,i3,0,1)*u ## rr4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,1)+rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3,kd)+rx(i1,i2,i3,1,0)*rx(i1,i2,i3,1,1)*u ## ss4(i1,i2,i3,kd)+rx ## x4 ## 2(i1,i2,i3,0,1)*u ## r4(i1,i2,i3,kd)+rx ## x4 ## 2(i1,i2,i3,1,1)*u ## s4(i1,i2,i3,kd)
u ## xz42(i1,i2,i3,kd)=0
u ## yz42(i1,i2,i3,kd)=0
u ## zz42(i1,i2,i3,kd)=0
u ## laplacian42(i1,i2,i3,kd)=(rx(i1,i2,i3,0,0)**2+rx(i1,i2,i3,0,1)**2)*u ## rr4(i1,i2,i3,kd)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0)+ rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1))*u ## rs4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,0)**2+rx(i1,i2,i3,1,1)**2)*u ## ss4(i1,i2,i3,kd)+(rx ## x4 ## 2(i1,i2,i3,0,0)+rx ## y4 ## 2(i1,i2,i3,0,1))*u ## r4(i1,i2,i3,kd)+(rx ## x4 ## 2(i1,i2,i3,1,0)+rx ## y4 ## 2(i1,i2,i3,1,1))*u ## s4(i1,i2,i3,kd)
u ## xx43(i1,i2,i3,kd)=rx(i1,i2,i3,0,0)**2*u ## rr4(i1,i2,i3,kd)+rx(i1,i2,i3,1,0)**2*u ## ss4(i1,i2,i3,kd)+rx(i1,i2,i3,2,0)**2*u ## tt4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0)*u ## rs4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,0)*u ## rt4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,0)*u ## st4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,0,0)*u ## r4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,1,0)*u ## s4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,2,0)*u ## t4(i1,i2,i3,kd)
u ## yy43(i1,i2,i3,kd)=rx(i1,i2,i3,0,1)**2*u ## rr4(i1,i2,i3,kd)+rx(i1,i2,i3,1,1)**2*u ## ss4(i1,i2,i3,kd)+rx(i1,i2,i3,2,1)**2*u ## tt4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1)*u ## rs4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,1)*u ## rt4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,1)*u ## st4(i1,i2,i3,kd)+rx ## y4 ## 3(i1,i2,i3,0,1)*u ## r4(i1,i2,i3,kd)+rx ## y4 ## 3(i1,i2,i3,1,1)*u ## s4(i1,i2,i3,kd)+rx ## y4 ## 3(i1,i2,i3,2,1)*u ## t4(i1,i2,i3,kd)
u ## zz43(i1,i2,i3,kd)=rx(i1,i2,i3,0,2)**2*u ## rr4(i1,i2,i3,kd)+rx(i1,i2,i3,1,2)**2*u ## ss4(i1,i2,i3,kd)+rx(i1,i2,i3,2,2)**2*u ## tt4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,2)*u ## rs4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,2)*u ## rt4(i1,i2,i3,kd)+2.*rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,2)*u ## st4(i1,i2,i3,kd)+rx ## z4 ## 3(i1,i2,i3,0,2)*u ## r4(i1,i2,i3,kd)+rx ## z4 ## 3(i1,i2,i3,1,2)*u ## s4(i1,i2,i3,kd)+rx ## z4 ## 3(i1,i2,i3,2,2)*u ## t4(i1,i2,i3,kd)
u ## xy43(i1,i2,i3,kd)=rx(i1,i2,i3,0,0)*rx(i1,i2,i3,0,1)*u ## rr4(i1,i2,i3,kd)+rx(i1,i2,i3,1,0)*rx(i1,i2,i3,1,1)*u ## ss4(i1,i2,i3,kd)+rx(i1,i2,i3,2,0)*rx(i1,i2,i3,2,1)*u ## tt4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,1)+rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,0))*u ## rt4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,0))*u ## st4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,0,1)*u ## r4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,1,1)*u ## s4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,2,1)*u ## t4(i1,i2,i3,kd)
u ## xz43(i1,i2,i3,kd)=rx(i1,i2,i3,0,0)*rx(i1,i2,i3,0,2)*u ## rr4(i1,i2,i3,kd)+rx(i1,i2,i3,1,0)*rx(i1,i2,i3,1,2)*u ## ss4(i1,i2,i3,kd)+rx(i1,i2,i3,2,0)*rx(i1,i2,i3,2,2)*u ## tt4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,0))*u ## rs4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,0))*u ## rt4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,0))*u ## st4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,0,2)*u ## r4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,1,2)*u ## s4(i1,i2,i3,kd)+rx ## x4 ## 3(i1,i2,i3,2,2)*u ## t4(i1,i2,i3,kd)
u ## yz43(i1,i2,i3,kd)=rx(i1,i2,i3,0,1)*rx(i1,i2,i3,0,2)*u ## rr4(i1,i2,i3,kd)+rx(i1,i2,i3,1,1)*rx(i1,i2,i3,1,2)*u ## ss4(i1,i2,i3,kd)+rx(i1,i2,i3,2,1)*rx(i1,i2,i3,2,2)*u ## tt4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,1))*u ## rs4(i1,i2,i3,kd)+(rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,1))*u ## rt4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,2)+rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,1))*u ## st4(i1,i2,i3,kd)+rx ## y4 ## 3(i1,i2,i3,0,2)*u ## r4(i1,i2,i3,kd)+rx ## y4 ## 3(i1,i2,i3,1,2)*u ## s4(i1,i2,i3,kd)+rx ## y4 ## 3(i1,i2,i3,2,2)*u ## t4(i1,i2,i3,kd)
u ## laplacian43(i1,i2,i3,kd)=(rx(i1,i2,i3,0,0)**2+rx(i1,i2,i3,0,1)**2+rx(i1,i2,i3,0,2)**2)*u ## rr4(i1,i2,i3,kd)+(rx(i1,i2,i3,1,0)**2+rx(i1,i2,i3,1,1)**2+rx(i1,i2,i3,1,2)**2)*u ## ss4(i1,i2,i3,kd)+(rx(i1,i2,i3,2,0)**2+rx(i1,i2,i3,2,1)**2+rx(i1,i2,i3,2,2)**2)*u ## tt4(i1,i2,i3,kd)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,1,0)+ rx(i1,i2,i3,0,1)*rx(i1,i2,i3,1,1)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,1,2))*u ## rs4(i1,i2,i3,kd)+2.*(rx(i1,i2,i3,0,0)*rx(i1,i2,i3,2,0)+ rx(i1,i2,i3,0,1)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,0,2)*rx(i1,i2,i3,2,2))*u ## rt4(i1,i2,i3,kd)+2.*(rx(i1,i2,i3,1,0)*rx(i1,i2,i3,2,0)+ rx(i1,i2,i3,1,1)*rx(i1,i2,i3,2,1)+rx(i1,i2,i3,1,2)*rx(i1,i2,i3,2,2))*u ## st4(i1,i2,i3,kd)+(rx ## x4 ## 3(i1,i2,i3,0,0)+rx ## y4 ## 3(i1,i2,i3,0,1)+rx ## z4 ## 3(i1,i2,i3,0,2))*u ## r4(i1,i2,i3,kd)+(rx ## x4 ## 3(i1,i2,i3,1,0)+rx ## y4 ## 3(i1,i2,i3,1,1)+rx ## z4 ## 3(i1,i2,i3,1,2))*u ## s4(i1,i2,i3,kd)+(rx ## x4 ## 3(i1,i2,i3,2,0)+rx ## y4 ## 3(i1,i2,i3,2,1)+rx ## z4 ## 3(i1,i2,i3,2,2))*u ## t4(i1,i2,i3,kd)
c============================================================================================
c Define derivatives for a rectangular grid
c
c============================================================================================
#If #OPTION == "RX"
dx ## 41(kd) = 1./(12.*dx(kd))
dx ## 42(kd) = 1./(12.*dx(kd)**2)
#End
u ## x43r(i1,i2,i3,kd)=(8.*(u(i1+1,i2,i3,kd)-u(i1-1,i2,i3,kd))-(u(i1+2,i2,i3,kd)-u(i1-2,i2,i3,kd)))*dx ## 41(0)
u ## y43r(i1,i2,i3,kd)=(8.*(u(i1,i2+1,i3,kd)-u(i1,i2-1,i3,kd))-(u(i1,i2+2,i3,kd)-u(i1,i2-2,i3,kd)))*dx ## 41(1)
u ## z43r(i1,i2,i3,kd)=(8.*(u(i1,i2,i3+1,kd)-u(i1,i2,i3-1,kd))-(u(i1,i2,i3+2,kd)-u(i1,i2,i3-2,kd)))*dx ## 41(2)
u ## xx43r(i1,i2,i3,kd)=( -30.*u(i1,i2,i3,kd)+16.*(u(i1+1,i2,i3,kd)+u(i1-1,i2,i3,kd))-(u(i1+2,i2,i3,kd)+u(i1-2,i2,i3,kd)) )*dx ## 42(0) 
u ## yy43r(i1,i2,i3,kd)=( -30.*u(i1,i2,i3,kd)+16.*(u(i1,i2+1,i3,kd)+u(i1,i2-1,i3,kd))-(u(i1,i2+2,i3,kd)+u(i1,i2-2,i3,kd)) )*dx ## 42(1) 
u ## zz43r(i1,i2,i3,kd)=( -30.*u(i1,i2,i3,kd)+16.*(u(i1,i2,i3+1,kd)+u(i1,i2,i3-1,kd))-(u(i1,i2,i3+2,kd)+u(i1,i2,i3-2,kd)) )*dx ## 42(2)
u ## xy43r(i1,i2,i3,kd)=( (u(i1+2,i2+2,i3,kd)-u(i1-2,i2+2,i3,kd)- u(i1+2,i2-2,i3,kd)+u(i1-2,i2-2,i3,kd)) +8.*(u(i1-1,i2+2,i3,kd)-u(i1-1,i2-2,i3,kd)-u(i1+1,i2+2,i3,kd)+u(i1+1,i2-2,i3,kd) +u(i1+2,i2-1,i3,kd)-u(i1-2,i2-1,i3,kd)-u(i1+2,i2+1,i3,kd)+u(i1-2,i2+1,i3,kd))+64.*(u(i1+1,i2+1,i3,kd)-u(i1-1,i2+1,i3,kd)- u(i1+1,i2-1,i3,kd)+u(i1-1,i2-1,i3,kd)))*(dx ## 41(0)*dx ## 41(1))
u ## xz43r(i1,i2,i3,kd)=( (u(i1+2,i2,i3+2,kd)-u(i1-2,i2,i3+2,kd)-u(i1+2,i2,i3-2,kd)+u(i1-2,i2,i3-2,kd)) +8.*(u(i1-1,i2,i3+2,kd)-u(i1-1,i2,i3-2,kd)-u(i1+1,i2,i3+2,kd)+u(i1+1,i2,i3-2,kd) +u(i1+2,i2,i3-1,kd)-u(i1-2,i2,i3-1,kd)- u(i1+2,i2,i3+1,kd)+u(i1-2,i2,i3+1,kd)) +64.*(u(i1+1,i2,i3+1,kd)-u(i1-1,i2,i3+1,kd)-u(i1+1,i2,i3-1,kd)+u(i1-1,i2,i3-1,kd)) )*(dx ## 41(0)*dx ## 41(2))
u ## yz43r(i1,i2,i3,kd)=( (u(i1,i2+2,i3+2,kd)-u(i1,i2-2,i3+2,kd)-u(i1,i2+2,i3-2,kd)+u(i1,i2-2,i3-2,kd)) +8.*(u(i1,i2-1,i3+2,kd)-u(i1,i2-1,i3-2,kd)-u(i1,i2+1,i3+2,kd)+u(i1,i2+1,i3-2,kd) +u(i1,i2+2,i3-1,kd)-u(i1,i2-2,i3-1,kd)-u(i1,i2+2,i3+1,kd)+u(i1,i2-2,i3+1,kd)) +64.*(u(i1,i2+1,i3+1,kd)-u(i1,i2-1,i3+1,kd)-u(i1,i2+1,i3-1,kd)+u(i1,i2-1,i3-1,kd)) )*(dx ## 41(1)*dx ## 41(2))
u ## x41r(i1,i2,i3,kd)= u ## x43r(i1,i2,i3,kd)
u ## y41r(i1,i2,i3,kd)= u ## y43r(i1,i2,i3,kd)
u ## z41r(i1,i2,i3,kd)= u ## z43r(i1,i2,i3,kd)
u ## xx41r(i1,i2,i3,kd)= u ## xx43r(i1,i2,i3,kd)
u ## yy41r(i1,i2,i3,kd)= u ## yy43r(i1,i2,i3,kd)
u ## zz41r(i1,i2,i3,kd)= u ## zz43r(i1,i2,i3,kd)
u ## xy41r(i1,i2,i3,kd)= u ## xy43r(i1,i2,i3,kd)
u ## xz41r(i1,i2,i3,kd)= u ## xz43r(i1,i2,i3,kd)
u ## yz41r(i1,i2,i3,kd)= u ## yz43r(i1,i2,i3,kd)
u ## laplacian41r(i1,i2,i3,kd)=u ## xx43r(i1,i2,i3,kd)
u ## x42r(i1,i2,i3,kd)= u ## x43r(i1,i2,i3,kd)
u ## y42r(i1,i2,i3,kd)= u ## y43r(i1,i2,i3,kd)
u ## z42r(i1,i2,i3,kd)= u ## z43r(i1,i2,i3,kd)
u ## xx42r(i1,i2,i3,kd)= u ## xx43r(i1,i2,i3,kd)
u ## yy42r(i1,i2,i3,kd)= u ## yy43r(i1,i2,i3,kd)
u ## zz42r(i1,i2,i3,kd)= u ## zz43r(i1,i2,i3,kd)
u ## xy42r(i1,i2,i3,kd)= u ## xy43r(i1,i2,i3,kd)
u ## xz42r(i1,i2,i3,kd)= u ## xz43r(i1,i2,i3,kd)
u ## yz42r(i1,i2,i3,kd)= u ## yz43r(i1,i2,i3,kd)
u ## laplacian42r(i1,i2,i3,kd)=u ## xx43r(i1,i2,i3,kd)+u ## yy43r(i1,i2,i3,kd)
u ## laplacian43r(i1,i2,i3,kd)=u ## xx43r(i1,i2,i3,kd)+u ## yy43r(i1,i2,i3,kd)+u ## zz43r(i1,i2,i3,kd)
#endMacro


#beginMacro declareDifferenceNewOrder4(u,rx,dr,dx,OPTION)
real dr ##14
real dr ##24
real u ##r4
real u ##s4
real u ##t4
real u ##rr4
real u ##ss4
real u ##tt4
real u ##rs4
real u ##rt4
real u ##st4
real rx ##r4
real rx ##s4
real rx ##t4
real u ##x41
real u ##y41
real u ##z41
real u ##x42
real u ##y42
real u ##z42
real u ##x43
real u ##y43
real u ##z43
real rx ##x41
real rx ##x42
real rx ##y42
real rx ##x43
real rx ##y43
real rx ##z43
real u ##xx41
real u ##yy41
real u ##xy41
real u ##xz41
real u ##yz41
real u ##zz41
real u ##laplacian41
real u ##xx42
real u ##yy42
real u ##xy42
real u ##xz42
real u ##yz42
real u ##zz42
real u ##laplacian42
real u ##xx43
real u ##yy43
real u ##zz43
real u ##xy43
real u ##xz43
real u ##yz43
real u ##laplacian43
real dx ##41
real dx ##42
real u ##x43r
real u ##y43r
real u ##z43r
real u ##xx43r
real u ##yy43r
real u ##zz43r
real u ##xy43r
real u ##xz43r
real u ##yz43r
real u ##x41r
real u ##y41r
real u ##z41r
real u ##xx41r
real u ##yy41r
real u ##zz41r
real u ##xy41r
real u ##xz41r
real u ##yz41r
real u ##laplacian41r
real u ##x42r
real u ##y42r
real u ##z42r
real u ##xx42r
real u ##yy42r
real u ##zz42r
real u ##xy42r
real u ##xz42r
real u ##yz42r
real u ##laplacian42r
real u ##laplacian43r
#endMacro
