typedef struct User{
    int blade_cnt;
    int assist_blade_cnt;
    int ratchet_cnt;
    int lock_chip_cnt;
    int bit_cnt;
    int simple_ratchet_cnt;
    char blade[1000][50];
    char assist_blade[100][50];
    char ratchet[100][50];
    char bit[100][50];
    char lock_chip[100][50];
    char simple_ratchet[100][50];
}User;
struct User Snek_blades={
    .blade_cnt=42, .assist_blade_cnt=8, .ratchet_cnt=21, .lock_chip_cnt=9, .bit_cnt=35, .simple_ratchet_cnt=1,
    .blade={"Eclipse", "Scorpio Spear", "Cobalt Dragoon", "Meteor Dragoon", "Crimson Garuda", "Dran Sword", "Knight Shield", "Leon Claw", "Phoenix Wing", "Samurai Calibur", "Shark Edge", "Sphinx Cowl", "Tyranno Beat", "Unicorn Sting", "Weiss Tiger", "Whale Wave", "Wizard Arrow", "Dran Buster", "Hells Hammer", "Impact Drake", "Leon Crest", "Samurai Saber", "Silver Wolf", "Wizard Rod",  "Lightning L-Drago", "Bite Croc", "Gill Shark", "Knife Shinobi", "Savvage Bear", "Steel Samurai", "Talon Ptera", "Arc", "Blast", "Brave", "Brush", "Dark", "Flame", "Reaper"},
    .assist_blade={"A", "B", "D", "J", "R", "S", "T", "W"},
    .ratchet={"Tr", "0-80", "1-60", "1-80", "2-60", "2-70", "3-60", "3-70", "3-80", "4-55", "4-60", "4-70", "4-80", "5-60", "5-70", "5-80", "6-60", "6-70", "6-80", "7-60", "9-60"},
    .bit={"TK", "Z", "A", "B", "J", "C", "DB", "E", "F", "FB", "GB", "GF", "GN", "GP", "H", "HN", "K", "L", "LF", "LO", "LR", "M", "MN", "N", "O", "P", "Q", "R", "S", "T", "TP", "U", "V", "W", "WB"},
    .lock_chip={"Wolf", "Sol", "Cerberus", "Dran", "Fox", "Hells", "Pegasus", "Perseus", "Wizard"},
    .simple_ratchet={"4-55"}
};
struct User bx={
    .blade_cnt=72, .assist_blade_cnt=0, .ratchet_cnt=15, .lock_chip_cnt=0, .bit_cnt=22, .simple_ratchet_cnt=1,
    .blade={"Black Shell", "Cobalt Dragoon", "Cobalt Drake", "Crimson Garuda", "Dran Dagger", "Dran Sword", "Hells Chain", "Hells Scythe", "Knight Lance", "Knight Shield", "Leon Claw", "Pheonix Feather", "Phoenix Wing", "Rhino Horn", "Samurai Calibur", "Shark Edge", "Shelter Drake", "Sphinx Cowl", "Tricera Press", "Tyranno Beat", "Unicorn Sting", "Viper Tail", "Weiss Tiger", "Whale Wave", "Wizard Arrow", "Wyvern Gale", "Bite Croc", "Gill Shark", "Knife Shinobi", "Ridge Triceratops", "Roar Tyranno", "Savage Bear", "Samurai Steel", "Tackle Goat", "Talon Ptera", "Tuck Mammoth", "Yell Kong", "Dragoon Storm", "Dranzer Spiral", "Driger Slash", "Draciel Shield", "Lightning L-Drago", "Rock Leone", "Storn Pegasus", "Victory Valkyrie", "Xeno Xcalibur", "Mosasaurus", "Quetzalcoatlus", "Spinosaurus", "T-Rex", "Captain America", "Green GOblin", "Iron Man", "Miles Morales", "Red Hulk", "Spder-Man", "Thanos", "Venom", "Chewbacca", "Darth Vader", "General Grievous", "Luke Skywalker", "Moff Gideon", "Obi-Wan Kenobi", "Stormtrooper", "The Mandalorian", "Bumblebee", "Megatron", "Optimus Primal", "Optimus Prime", "Shockwave", "Starscream"},
    .ratchet={"1-70", "2-60", "2-80", "3-60", "3-80", "4-60", "4-70", "4-80", "5-60", "5-80", "6-70", "7-70", "9-60", "9-80", "M-85"},
    .bit={"B", "C", "D", "E","F", "GB", "GF", "GN", "GP", "HN", "HT", "LF", "M", "N", "O", "P", "Q", "R", "S", "T", "TP", "U"},
    .simple_ratchet={"M-85"}
};
struct User ux={
    .blade_cnt=21, .assist_blade_cnt=0, .ratchet_cnt=14, .lock_chip_cnt=0, .bit_cnt=14, .simple_ratchet_cnt=3,
    .blade={"Aero Pegasus", "Clock Mirage", "Dran Buster", "Ghost Circle", "Golem Rock", "Hells Hammer", "Impact Drake", "Kight Mail", "Leon Crest", "Meteor Dragoon", "Mummy Curse", "Orochi Cluster", "Pheonix Rudder", "Samurai Saber", "Scorpio Spear", "Shark Scale", "Shinobi Shadow", "Silver Wolf", "Wizard Rod", "Hover Wyvern", "Stun Medusa"},
    .ratchet={"0-70", "0-80", "2-70", "3-70", "3-85", "7-60", "7-70", "7-75", "1-60", "1-80", "9-65", "9-70", "4-50", "5-70"},
    .bit={"A", "BS", "DB", "FB", "G", "H", "J", "L", "LR", "MN", "RA", "UF", "UN", "Z"},
    .simple_ratchet={"3-85", "7-55", "9-65"}
};
struct User cx={
    .blade_cnt=16, .assist_blade_cnt=13, .ratchet_cnt=6, .lock_chip_cnt=17, .bit_cnt=8, .simple_ratchet_cnt=1,
    .lock_chip={"Cerberus", "Dran", "Fox", "Hells", "Hornet", "Kraken", "Leon", "Emperor", "Pegasus", "Perseus", "Phoenix", "Sol", "Stag", "Valkyrie", "Whale", "Wolf", "Wizard"},
    .blade={"Antler", "Arc", "Blast", "Brave", "Brush", "Dark", "Eclipse", "Fang", "Flame", "Flare", "Fort", "Hunt", "Might", "Reaper", "Volt", "Wriggle"},
    .assist_blade={"A", "B", "C", "D", "F", "H", "J", "M", "R", "S", "T", "W", "Z"},
    .ratchet={"0-60", "4-55", "6-60", "6-80", "Op", "Tr"},
    .bit={"GR", "K", "LO", "TK", "V", "WB", "WW", "W"},
    .simple_ratchet={"4-55"}
};
struct User Yako={
    .blade_cnt=12, .assist_blade_cnt=1, .lock_chip_cnt=1, .ratchet_cnt=11, .bit_cnt=12, .simple_ratchet_cnt=2,
    .blade={"Whale Wave", "Leon Claw", "Gill Shark", "Phoenix Wing", "Arc", "Shark Edge", "Clock Mirage", "Wizard Arrow", "Sphinx Cowl", "Viper Tail", "Leon Crest", "Golem Rock"},
    .assist_blade={"R"},
    .lock_chip={"Wizard"},
    .ratchet={"5-80", "5-60", "9-65", "4-55", "9-60", "3-60", "4-80", "1-80", "5-70", "1-60", "7-60"},
    .bit={"GF", "UN", "F", "D", "H", "GN", "GB", "O", "T", "HN", "B", "Q"},
    .simple_ratchet={"4-55", "9-65"}
};
struct User Ben={
    .blade_cnt=19, .assist_blade_cnt=3, .lock_chip_cnt=4, .ratchet_cnt=11, .bit_cnt=18, .simple_ratchet_cnt=2,
    .blade={"Whale Wave", "Silver Wolf", "Scorpio Spear", "Cobalt Dragoon", "Might", "Meteor Dragoon", "Wizard Rod", "Unicorn Sting", "Bear Scratch", "Impact Drake", "Wyvern Gale", "Arc", "Wizard Arrow", "Dran Sword", "Fort", "Brush", "Lightning L-Drago", "Knight Lance", "Leon Claw"},
    .assist_blade={"H", "J", "R"},
    .lock_chip={"Fox", "Emperor", "Wizard", "Hornet"},
    .ratchet={"1-60", "Op", "5-60", "M-85", "3-80", "7-60", "2-70", "5-70", "4-55", "0-70", "5-80", "3-60"},
    .bit={"K", "F", "L", "T", "RA", "B", "P", "GF", "S", "Z", "N", "HN", "GP", "FB", "DB", "HT", "LF"},
    .simple_ratchet={"M-85", "4-55"}
};
int testnum=1;
char user_test[1000][50]={"Clock Mirage"};