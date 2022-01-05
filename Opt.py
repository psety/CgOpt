

G_mot = 55
G_elect = 1500
G_additional = 76

#All metrics are mm.
ss_range=0.2                #Stability Range

solar_panel_x = 140
solar_panel_y = 80

nose_range   = 200
wing_x_range = range(solar_panel_x,280,solar_panel_x)
wing_y_range = range(solar_panel_y,280,solar_panel_y)
tail_x_range = 280
tail_y_range = 700
lt_size_range = 1300
i_w_range = range(-30, 30 , 1)
i_t_range = range(-30, 30 , 1)

cbar_list = []


# Some components' weights are fixed. Electronic Board, Battery, Motor-ESCs...
# Wing and tail is proportional with size.


for nose_size in range(nose_range):                                                     # Nose Point
    for wing_x_size in wing_x_range:                                                    # Wing Chord - cbar
        for wing_y_size in wing_y_range:                                                # Wing Span  - b
            for lt_size in range(lt_size_range):                                        # Wing Edge Point - Tail AC distance
                for tail_x_size in range(tail_x_range):                                 # Tail Chord -tbar or sth else. what you call it. 
                    for tail_y_size in range(tail_y_range):                             # Tail span.
                        for i_w in i_w_range:                                           # incidince angle of the wing
                            for i_t in i_t_range:                                       # incidence angle og the tail
                                cbar = wing_x_size*(10/7)                               # Hinge of the aileron is located at 70%
                                
                                """
                                if(wing_y_size > 120):                                  # Maybe ignored at the first stages of development.
                                    G_mot = G_mot*2                                     # number of the motors are 2 if span is below 1200mm. Why ? I Don't know... 
                                else:
                                    G_mot = G_mot*4
                                """
                                G_mot = G_mot*4
                                G_wing = (wing_x_size*wing_y_size/(100*100))*1.5        # grams                                                                                                    
                                G_rudder = 150
                                G_fs = 0                                                # fuselage is ignored. 
                                G_elev = (tail_x_size*tail_y_size/(100*100))*1.5        # F.king roughly calculation is made as like as wing. Vol_wing*d_straphore. 
                                


                                
                                #print("nose size: {}\nwing_x_size: {}\nwing_y_size: {}\nlt_size: {}\ntail_x_size: {}\ntail_y_size: {}\ni_w: {}\ni_t: {}\n".format(nose_size,wing_x_size,wing_y_size,lt_size,tail_x_size,tail_y_size,i_w,i_t))
                                if cbar not in cbar_list:
                                    cbar_list.append(cbar)
                                    for cbarlistin in cbar_list:
                                        print(cbarlistin)
