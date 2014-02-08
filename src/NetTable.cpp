#include <NetworkTable.hpp>

using namespace std;

NetworkTable::NetworkTable{
         table = NetworkTableTools::GetClientTable(ipAdress, "Vision");       
}

NetworkTable::sendPoint(int x, int y, string key){
        table->PutNumber("X" + key, x);
        table->PutNumber("Y" + key, y);
}

NetworkTable::sendDetection(bool detected, string key){
        table->PutBoolean(key, detected);
}
