/*this file is the loop part of a abstraction layer between hard- and software .e.g pointing inputs to variable
*/


/*buttons and switches
*/
brewSwitch.tick();  
steamSwitch.tick();
waterSwitch.tick();
powerSwitch.tick();

if (brewSwitch.getSingleClick() == true && requestBrew == false) {
    requestBrew = true;
}

if (steamSwitch.getSingleClick() == true && steamSwitch.getSingleClick() != requestSteamPrevious) {
    requestSteam = !requestSteam;
    requestSteamPrevious = requestSteam;
}

if (waterSwitch.getSingleClick() == true && waterSwitch.getSingleClick() != requestWaterPrevious) {
    requestWater = !requestWater;
    requestWaterPrevious = requestWater;
}

if (powerSwitch.getSingleClick() == true && powerSwitch.getSingleClick() == requestPowerPrevious) {
    pidMode = !pidMode;
    requestPowerPrevious = pidMode;    
}

/*Led stuff
*/

brewLed.update();
if (requestBrew == true){
    brewLed.setOnSingle();
}
else {
    brewLed.setOffSingle();
}
steamLed.update();
if (requestSteam == true){
    steamLed.setOnSingle();
}
else {
    steamLed.setOffSingle();
}
waterLed.update();
if (requestWater == true){
    waterLed.setOnSingle();
}
else {
    waterLed.setOffSingle();
}
powerLed.update();
if (pidMode == 1){
    waterLed.setOnSingle();
}
else {
    waterLed.setOffSingle();
}
statusLed.update();
if ((machinestate == kPidNormal && (fabs(Input - setPoint) < 0.5)) || (Input > 115 && fabs(Input - BrewSetPoint) < 5)) {
      statusLed.setOffSingle();
}
else {
    statusLed.setOnSingle();
}