// I declare, upon my honor, that I did this machine problem assignment as a
// collaboration with Rhys Theodore Barriga (Block A), Jon Alexander Llenes (Block B), and Lance Antig (Block C).
// Further, my solution is not a copy of any of my collaborators.

#include <stdio.h>
#include <string.h>

typedef enum {
    wooden_spear = 1,
    silver_ax = 2,
    diamond_scythe = 3
} weaponType;

typedef struct {
    weaponType type;
    int damage; 
    char name[20];
} weapon;

typedef enum {
    wooden_shield = 1,
    silver_shield = 2,
    diamond_shield = 3
} shieldType;

typedef struct {
    shieldType type;
    int damage;
    char name[20];
} shield;

typedef struct {
    int health, mana, jade, blink;
    weapon wpn;
    shield shld;
} bantugan;

void gameplay (bantugan [], int, int, int, int, int);

int main() {

    int cases, turns, player_first_turn = 0, attacker, defender, jade_use, shield_up, blink_use, fight_end;

    bantugan b[2];

    scanf("%i", &cases);
    
    while (cases--) {
        b[0].health = b[0].mana = 10;
        b[1].health = b[1].mana = 10;
        fight_end = 0;

        for (int i = 0; i < 2; i++) {
            scanf("%i%i", &b[i].wpn.damage, &b[i].shld.damage);
            
            if (b[i].wpn.damage == 1) {
                b[i].wpn.type = wooden_spear;
                strcpy (b[i].wpn.name, "Wooden Spear");
            }
            else if (b[i].wpn.damage == 2) {
                b[i].wpn.type = silver_ax;
                strcpy (b[i].wpn.name,"Silver Ax");
            }
            else if (b[i].wpn.damage == 3) {
                b[i].wpn.type = diamond_scythe;
                strcpy (b[i].wpn.name,"Diamond Scythe");
            }
            
            if (b[i].shld.damage == 1) {
                b[i].shld.type = wooden_shield;
                strcpy (b[i].shld.name, "Wooden Shield");
            }
            else if (b[i].shld.damage == 2) {
                b[i].shld.type = silver_shield;
                strcpy (b[i].shld.name,"Silver Shield");
            }
            else if (b[i].shld.damage == 3) {
                b[i].shld.type = diamond_shield;
                strcpy (b[i].shld.name,"Diamond Shield");
            }
        }
        
        scanf ("%i", &player_first_turn);
        scanf ("%i", &turns);

        for (int i = 0; i < 2 * turns; i++) {
            if (i % 2 == 0) {
                b[0].mana += 2;
                if (b[0].mana > 10) {
                    b[0].mana = 10;
                }
                
                b[1].mana += 2;
                if (b[1].mana > 10) {
                    b[1].mana = 10;
                }
            }
            
            if ((player_first_turn == 1 && i % 2 == 0 ) || ( player_first_turn == 2 && i % 2 == 1)) {
                attacker = 0;
                defender = 1;
            } else {
                attacker = 1;
                defender = 0;
            }

            if (player_first_turn == 1) {
                scanf ("%i%i%i%i", &b[0].jade, &b[0].blink, &b[1].jade, &b[1].blink);
            } else {
                scanf ("%i%i%i%i", &b[1].jade, &b[1].blink, &b[0].jade, &b[0].blink);
            }

            scanf ("%i%i%i", &jade_use, &shield_up, &blink_use);

            gameplay(b, attacker, defender, jade_use, shield_up, blink_use);
            
            if (fight_end == 0) {
                printf ("BANTUGAN TIMAN\n");
                printf ("Health: %i Mana: %i Weapon: %s Shield: %s Jade Palapa: %i Bai-a-Labi's Blink: %i\n", b[0].health, b[0].mana, b[0].wpn.name, b[0].shld.name, b[0].jade, b[0].blink);
                printf ("BANTUGAN DUA\n");
                printf ("Health: %i Mana: %i Weapon: %s Shield: %s Jade Palapa: %i Bai-a-Labi's Blink: %i\n", b[1].health, b[1].mana, b[1].wpn.name, b[1].shld.name, b[1].jade, b[1].blink);
                
                if (b[0].health == 0 && b[1].health == 0) {
                    printf ("DRAW! BOTH BANTUGANS SUCCUMBED AND WILL BE OFFERED TO LAKE RANAO AS SACRIFICE. MAY THE PAPANOKA MRA REWARD THEM GRACIOUSLY.\n");
                } else if (b[0].health == 0) {
                    printf ("BANTUGAN TIMAN FALLS! MAY THE PAPANOKA MRA REWARD HIS COURAGE GRACIOUSLY. TO THE LAKE RANAO!\n");
                } else if (b[1].health == 0) {
                    printf ("BANTUGAN DUA FALLS! MAY THE PAPANOKA MRA REWARD HIS COURAGE GRACIOUSLY. TO THE LAKE RANAO!\n");
                }
                
                if (b[0].health == 0 || b[1].health == 0) {
                    fight_end = 1;
                }
            }
        }
    }
    
    return 0;
}

void gameplay (bantugan b[], int attacker, int defender, int jade_use, int shield_up, int blink_use)
{
    if (jade_use && b[attacker].mana >= 6 && b[attacker].jade == 1) {
        b[attacker].mana -= 6;
        b[attacker].jade -= jade_use;
        
        if (blink_use && b[defender].mana >= 6 && b[defender].blink == 1) {
            b[defender].mana -= 6;
            b[defender].blink -= blink_use;
        } else {
            b[defender].health -= 4;
        }
    } 
    else if (!jade_use) {
        if (shield_up) {
            if (b[defender].shld.damage > b[attacker].wpn.damage) {
                b[attacker].health -= b[attacker].wpn.damage;
            } 
            else if (b[attacker].wpn.damage > b[defender].shld.damage) {
                if (b[attacker].wpn.damage == 2 && b[defender].shld.damage == 1) {
                    b[defender].health -= 1;
                } 
                else if (b[attacker].wpn.damage == 3 && b[defender].shld.damage == 1) {
                    b[defender].health -= 3;
                } 
                else if (b[attacker].wpn.damage == 3 && b[defender].shld.damage == 2) {
                    b[defender].health -= 2;
                }
            }
        } 
        else {   
            b[defender].health -= b[attacker].wpn.damage;
        }
    }
    
    if (b[attacker].health < 0) {
        b[attacker].health = 0;
    }
    if (b[defender].health < 0) {
        b[defender].health = 0;
    }
}