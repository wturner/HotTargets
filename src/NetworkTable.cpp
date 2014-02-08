
NetworkTable::NetworkTable{
         table = NetworkTableTools::GetClientTable(ipAdress, "rioTable");       
}

NetworkTable::sendPoint(int x, int y){
        table->PutNumber("XCoordinate", x);
        table->PutNumber("YCoordinate", y);
}

NetworkTable::sendIfDetected(bool detected){
        table->PutBool("IfDetected", detected);       
}
