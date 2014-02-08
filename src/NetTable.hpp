#ifndef NETWORK_TABLE_HPP
#define NETWORK_TABLE_HPP

#include <iostream>
#include <tables/ITable.h>
#include <string>
#include <nttools/NetworkTableTools.h>

using namespace std;

class NetworkTable{
   
   public:
        namespace {
                static const string redBallXKey = "redBallX";
                static const string redBallYKey = "redBallY";
                static const string redBallDetection = "redBallDetected";
               
                static const string blueBallXKey = "blueBallX";
                static const string blueBallYKey = "blueBallY";
                static const string blueBallDetection = "blueBallDetected";
                 
                static const string horizontalXKey = "horizontalX";
                static const string horizontalYKey = "horizontalY";
                static const string horizontalDetection = "horizontalDetected";

                static const string verticalXKey = "verticalX";
                static const string verticalYKey = "verticalY";
                static const string verticalDetection = "verticalDetected";

        } 

        string ipAdress;

        string tableID;       
        
        //default values go here
        ITable * table;
        
        //sends the point
        void sendPoint(int x, int y, string key);
        void sendDetection(bool detected, string key);
}
#endif

//Argument Parser if ever needed
/*
      //argument parser
        for(int i = 0; i < argc; i++){
                if( string(argv[i]) == "-IP" ||  string(argv[i]) == "--IPAdress"){

                        ipAdress = argv[i + 1];
                }
                else if(string(argv[i]) == "-ID" || string(argv[i]) == "--IDName"){
                        
                        tableID = argv[i + 1];
                }
                else if(string(argv[i]) == "--help"){
                        cout << "-IP || --IPAdress \t\t\t sets the ip adress server to connect to" << endl;
                        cout << "-ID || --IDName \t\t\t sets the name of the table to be found" << endl;
                }
        }
        
        if(table == NULL){
                cout << "Table not found" << endl;
                
                //might need to change this
                return -1;
        }
        cout << "It works" << endl;
   
 */
