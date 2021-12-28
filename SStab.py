
cbar = 0.4
G_wing = 1200                                                                       # grams
G_rudder = 150
G_fs = 0
G_elev = 125
G_mot = 220
G_elect = 1500
G_additional = 76
m_grams = (G_wing + G_elev + G_rudder + G_fs + G_mot + G_elect) + G_additional      # grams

# [X, Y, Z ]
# wing_we = [Xw,Yw,Zw]
# ele_we = [Xele,Yele,Zele]
# rud_we = [Xr,Yr,Zr]
# fuse_we	= [Xf,Yf,Zf]
# motors_we = [Xm,Ym,Zm] 
# elec_we = [Xe,Ye,Ze]

wing_we     =   [0,     0,     0]
ele_we      =   [1.6,   0, -0.12]
rud_we      =   [1.6,   0,  -0.1]
fuse_we	    =   [0,     0,     0]
motors_we   =   [0,     0, -0.05] 
elec_we     =   [-0.25, 0,  -0.1]
addit_we    =   [0.38,  0,     0]

Xcg = (wing_we[0]*G_wing + ele_we[0]*G_elev + rud_we[0]*G_rudder + fuse_we[0]*G_fs + motors_we[0]*G_mot + elec_we[0]*G_elect + addit_we[0]*G_additional)/m_grams
Ycg = 0
Zcg = (wing_we[2]*G_wing + ele_we[2]*G_elev + rud_we[2]*G_rudder + fuse_we[2]*G_fs + motors_we[2]*G_mot + elec_we[2]*G_elect + addit_we[2]*G_additional)/m_grams
CoG = [Xcg,Ycg,Zcg]

Xac = wing_we[0] + (cbar*0.25)
print("CoG_x : {}\nCoG_y : {}\nCoG_z : {}.\n".format(CoG[0], CoG[1], CoG[2]))
#print(f"CoG_x : {Xcg}, CoG_y :{CoG[1]}, CoG_z :{CoG[2]}. ")
m_kg = m_grams/1000

print("Xcg - Xac")
SS_distance = Xcg - Xac 