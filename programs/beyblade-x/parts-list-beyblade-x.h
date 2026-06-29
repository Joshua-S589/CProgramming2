#ifndef PARTS_LIST_BEYBLADE_X_H
#define PARTS_LIST_BEYBLADE_X_H
int bladecnt=99;
int uxExtendedcnt=5;
int mainBladecnt=16;
int metalBladecnt=6;
int assistBladecnt=18;
int overBladecnt=6;
int ratchetIntegratedBitcnt=2;
int ratchetcnt=35;
int bitcnt=50;
int mlccnt=2;
int plccnt=23;
int simpleRatchetcnt=5;
int simpleBladecnt=1;
int bladeBxcnt=30;
int bladeUxcnt=21;
int clockMiragenum=1;
char blade[126][50]={"Aether Ring", "Black Shell", "Cobalt Dragoon", "Cobalt Drake", "Crimson Garuda", "Croc Crunch", "Dran Dagger", "Dran Strike", "Dran Sword", "Hells Chain", "Hells Scythe", "Horus Shatter", "Knight Lance", "Knight Shield", "Leon Claw", "Phoenix Feather", "Phoenix Wing", "Rhino Horn", "Samurai Calibur", "Shark Edge", "Shelter Drake", "Sphinx Cowl", "Tricera Press", "Tyranno Beat", "Unicorn Sting", "Viper Tail", "Weiss Tiger", "Whale Wave", "Wizard Arrow", "Wyvern Gale",
     "Aero Pegasus", "Clock Mirage", "Dran Buster", "Ghost Circle", "Golem Rock", "Hells Hammer", "Hover Wyvern", "Impact Drake", "Knight Mail", "Leon Crest", "Mummy Cusrse", "Orochi Cluster", "Phoenix Rudder", "Samurai Saber", "Scorpio Spear", "Shark Scale", "Shinobi Shadow", "Silver Wolf", "Stun Medusa", "Viking Hack", "Wizard Rod", 
     "Draciel Shield", "Dragoon Storm", "Dranzer Spiral", "Driger Slash", "Lightning L-Drago", "Rock Leon", "Storm Pegasus", "Storm Spriggan", "Victory Valkyrie", "Xeno Xcalibur",
     "Clamp Crab", "Gill Shark", "Knife Shinobi", "Ridge Triceratops", "Roar Tyranno", "Savvage Bear", "Steel Samurai", "Tackle Goat", "Talon Ptera", "Tusk Mammoth", "Yell Kong",
     "Bumblebee", "Megatron", "Optimus Primal", "Optimus Prime", "Shockwave", "Starscream", "Chewbacca", "Darth Vader", "General Grievous", "Luke Skywalker", "Moff Gideon", "Obi-Wan Kenobi", "Stormtrooper", "The Mandalorian", "Captain America", "Green Goblin", "Iron Man", "Miles Morales", "Red Hulk", "Spider-Man", "Thanos", "Venom", "Mosasaurus", "Quetzalcoatlus", "Spinosaurus", "T Rex",
     "Aegis Rampart", "Bison Burrow", "Bullet Griffon", "Glory Valkyrie", "Shinobi Cutter",
     "Arc", "Blast", "Brave", "Brush", "Dark", "Eclipse", "Fang", "Flame", "Flare", "Hunt", "Might", "Reaper", "Volt", "Antler", "Fort", "Wriggle",
     "Blitz", "Delta", "Fortress", "Hurricane", "Rage", "Whip"};
char assist_blade[18][50]={"A", "B", "C", "D", "E", "F", "G", "H", "J", "K", "M", "O", "R", "S", "T", "V", "W", "Z"};
char ratchet[37][50]={"3-85", "4-55", "M-85", "7-55", "9-65", "Op", "Tr", "0-60", "0-70", "0-80", "1-50", "1-60", "1-70", "1-80", "2-60", "2-70", "2-80", "3-60", "3-70", "3-80", "4-50", "4-60", "4-70", "4-80", "5-60", "5-70", "5-80", "6-60", "6-70", "6-80", "7-60", "7-70", "7-80", "8-70", "9-60", "9-70", "9-80"};
char bit[50][50]={"A", "B", "BS", "C", "D", "DB", "DS", "E", "F", "FF", "FB", "G", "GB", "GF", "GN", "GP", "GR", "GU", "H", "HN", "HT", "I", "J", "K", "L", "LF", "LO", "LR", "M", "MN", "N", "Nr", "O", "P", "Q", "R", "RA", "S", "T", "TK", "TP", "U", "UF", "UN", "V", "W", "WB", "WW", "Y", "Z"};
char lock_chip[25][50]={"Valkyrie", "Emperor", "Bahamut", "Brachio", "Cerberus", "Drake", "Dran", "Enlil", "Eva", "Fox", "Hells", "Hornet", "Knight", "Kraken", "Pegasus", "Perseus", "Phoenix", "Ragna", "Rhino", "Sol", "Stag", "Unicorn", "Whale", "Wizard", "Wolf"};
char over_blade[6][50]={"B", "D", "F", "G", "I", "O"};
char simple_ratchet[5][50]={"3-85", "4-55", "M-85", "7-55", "9-65"};
char simple_blade[1][50]={"Clock Mirage"};
int bladeCollection1[121];
int bladeCollectionClone1[121];
int bladeCollection2[121];
int bladeCollectionClone2[121];
int assistBladeCollection1[17];
int assistBladeCollectionClone1[17];
int assistBladeCollection2[17];
int assistBladeCollectionClone2[17];
int overBladeCollection1[5];
int overBladeCollectionClone1[5];
int overBladeCollection2[5];
int overBladeCollectionClone2[5];
int ratchetCollection1[37];
int ratchetCollectionClone1[37];
int ratchetCollection2[37];
int ratchetCollectionClone2[37];
int bitCollection1[50];
int bitCollectionClone1[50];
int bitCollection2[50];
int bitCollectionClone2[50];
int lockChipCollection1[23];
int lockChipCollectionClone1[23];
int lockChipCollection2[23];
int lockChipCollectionClone2[23];
int simpleRatchetCollection1[5];
int simpleRatchetCollectionClone1[5];
int simpleRatchetCollection2[5];
int simpleRatchetCollectionClone2[5];
char combo_list_player_1[1000][1000];
char combo_list_player_2[1000][1000];
char blade_final[1000];
char blade_a[100];
#endif