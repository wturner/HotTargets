#include <NetTable.hpp>

using namespace std;

NetTable::NetTable{
        ipAddress = "127.0.0.1";
}

NetTable::sendPoint(int x, int y, string key){
        table->PutNumber("X" + key, x);
        table->PutNumber("Y" + key, y);
}

NetTable::sendDetection(bool detected, string key){
        table->PutBoolean(key, detected);
}

NetTable::setIPAddress(string addr){
        ipAddress = addr;
}

NetTable::openConnection(){
       table = NetworkTableTools::GetClientTable(ipAddress, "Vision");
}
