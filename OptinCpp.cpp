/*
 * Opt.py may be [certainly it is!] slow because of the complexity of the inner and inner for loops. 
 * Now the Algorithm Optimization is not considered. 
 * dat to csv web page: https://mypages.iit.edu/~aiaa/dat2csv ---> hilarious!! [Saved me for the future]
 */
#include <iostream>
#include <vector>

int main()
{
    
    int tot_count = 0;
    int ss_count = 0;
    // All metrics are mm.
    // Variables which are 

    float ss_range      = 0.2;                    // Stability Range. No need to be used
    float solar_panel_x = 140;                    // Solar panel x size
    float solar_panel_y = 80;                     // solar panel y size
    float nose_range    = 200;                    // range of the nose. get the middle point roughly for the g point
    float wing_y_range  = 320;                    // wing span
    float wing_x_range  = 2*solar_panel_x;        // wing chord's 70%. Hinge point at the 70. 
    float tail_x_range  = 280;                    // tail chord's of 70%
    float tail_y_range  = 700;                    // tail span
    float lt_size_range = 1300;                   // infact this should be considered end of the wing to tail ac [CARE]
    float i_w_range_min = -30;                    // i_w min
    float i_w_range_max = 30;                     // i_w max
    float i_t_range_min = -30;                    // i_t min
    float i_t_range_max = 30;                     // i_t max
    float hinge         = 10.0/7.0;

    for (float nose_in = 200; nose_in <= nose_range; nose_in = nose_in + 100)                                           // FOR-NOSE
    {
        //std::cout << "N: " << nose_in;

        for (float wing_Xin = solar_panel_x; wing_Xin <= wing_x_range; wing_Xin = wing_Xin + solar_panel_x)             // FOR-XWING
        {
            
            //std::cout << " Wx :" << wing_Xin;

            float chord = wing_Xin * hinge;
            float Sol_x = wing_Xin / solar_panel_x;

            for (float wing_Yin = solar_panel_y; wing_Yin <= 5 * chord; wing_Yin = wing_Yin + solar_panel_y)            // FOR-YWING
            {
                
                float Sol_y = wing_Yin / solar_panel_y;
                float totalSolar_w = Sol_x * Sol_y;
                
                //std::cout << " Wy: " << wing_Yin;
                for(float tail_Xin = solar_panel_x; tail_Xin <= 2*solar_panel_x ; tail_Xin = tail_Xin + solar_panel_x)          // FOR-XTAIL
                {
                    float tail_chord = tail_Xin * hinge;
                    //std::cout << " Tx: " << tail_Xin;

                    for (float tail_Yin = solar_panel_y; tail_Yin <= 3*tail_Xin; tail_Yin = tail_Yin + solar_panel_y)    // FOR-YTAIL
                    {
                        float totalSolar_t = (tail_Xin / solar_panel_x)*(tail_Yin/solar_panel_y);
                        float totalSolar = totalSolar_w + totalSolar_t;

                        //std::cout << " Ty: " << tail_Yin;
                        //std::cout << " Tot_solar: " << totalSolar;

                        for(float wt_dist = 0; wt_dist <= 1300; wt_dist=wt_dist+10)                                     // FOR WT-DISTANCE
                        {
                            
                            float Xnose = nose_in / 2.0;                                        // Nose/2-> Middle Point of the nose mass. 
                            float Xwing = chord/4.0;
                            float Xmot = 0.05;
                            float Xele = -0.1;
                            float Xtail = chord + wt_dist + tail_Xin/4.0;
                            float Xrud = Xtail;

                            float G_mot = 55*2;
                            float G_ele = 1500;
                            float G_add = 76;
                            float G_nose = 100;
                            float G_wing = ((wing_Xin * wing_Yin)/10000)*25;
                            float G_tail = ((tail_Xin * tail_Yin)/10000)*25;
                            float G_rud = 100;

                            float G_all = G_ele+G_nose+G_wing+G_mot+G_tail+G_rud;

                            float Xcg = (Xele*G_ele + Xnose*G_nose + Xwing * G_wing + Xmot*G_mot + Xtail*G_tail + Xrud*G_rud)/G_all;
                            //std::cout << "Xcg: " << Xcg << std::endl;
                            tot_count++;
                            float Xac = chord * 0.25;
                            float ss = Xcg - Xac;
                            //std::cout << "ss: " << ss << std::endl;
                            if (ss < 0)
                            {
                                std::cout <<"ss: " << ss << " Xw: " << wing_Xin << " Yw: " << wing_Yin << " Xt: " << tail_Xin << " Yt: " << tail_Yin << " lt: " << Xcg-Xtail <<" Mass: " << G_all <<" Gwing: "<<G_wing <<" Gtail: "<< G_tail << " chord: "<< chord<< std::endl;
                                ss_count++;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "Total Counter: " << tot_count <<  std::endl;
    std::cout << "SS Counter: " << ss_count <<  std::endl;
    return 0;
}