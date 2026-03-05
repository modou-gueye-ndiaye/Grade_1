//  Chapitre 4, exercice 4.3.

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//--- date : constantes, type et fonctions -------------------------------------

enum {
  january, february, march,
  april, may, june,
  july, august, september,
  october, november, december
};

#define DAY_MIN   1
#define DAY_MAX   31
#define MONTH_MIN january
#define MONTH_MAX december
#define YEAR_MIN  1583  // année qui suit l'instauration du calendrier grégorien
#define YEAR_MAX  2030  // sans illusion sur la pérennité de ce programme

const int daymax[][12] = {
  //  année non bissextile
  [false] = {
    [january] = DAY_MAX, [february] = DAY_MAX - 3, [march] = DAY_MAX,
    [april] = DAY_MAX - 1, [may] = DAY_MAX, [june] = DAY_MAX - 1,
    [july] = DAY_MAX, [august] = DAY_MAX, [september] = DAY_MAX - 1,
    [october] = DAY_MAX, [november] = DAY_MAX - 1, [december] = DAY_MAX,
  },
  //  année bissextile
  [true] = {
    [january] = DAY_MAX, [february] = DAY_MAX - 2, [march] = DAY_MAX,
    [april] = DAY_MAX - 1, [may] = DAY_MAX, [june] = DAY_MAX - 1,
    [july] = DAY_MAX, [august] = DAY_MAX, [september] = DAY_MAX - 1,
    [october] = DAY_MAX, [november] = DAY_MAX - 1, [december] = DAY_MAX,
  }
};

typedef struct {
  uint8_t day;
  uint8_t month;
  uint16_t year;
} date;

//  date_initialization : renvoie une structure de nom de type date
//    correspondant aux données fournies. Provoque une terminaison anormale du
//    programme si les données ne sont pas cohérentes.
date date_initialization(int day, int month, int year);

//  date_is_anniversary : renvoie true ou false selon que la date dcalendar est
//    une date anniversaire relativement à la date dreference ou non.
bool date_is_anniversary(date dcalendar, date dreference);

//--- fellow : macroconstantes, types et fonctions -----------------------------

#define NAME_LENGTH_MAX 31

typedef enum {
  male, female, other,
} gender;

typedef struct {
  char lastname[NAME_LENGTH_MAX + 1];
  char firstname[NAME_LENGTH_MAX + 1];
  gender gndr;
  date dbirth;
} identity;

typedef enum {
  single,
  married, civilunion,
  divorced, widowed,
} status;

typedef struct {
  identity ident;
  status stts;
  union {
    //  stts == married || stts == civilunion
    struct {
      identity ident;
      date dspouse;
    } spouse;
    //  stts == divorced || stts == widowed
    date dbreakup;
  } u;
} fellow;

//  identity_print_title_name : affiche le titre, le prénom et le nom liés à
//    l'identité pointée par idptr.
void identity_print_title_name(const identity *idptr);

//  fellow_print_reminder : affiche un message saluant le quidam pointé par
//    flwptr. Affiche un message complémentaire si le jour spécifié par d est
//    le jour anniversaire de son conjoint ou sa conjointe.
void fellow_print_reminder(const fellow *flwptr, date d);

//--- fonction principale ------------------------------------------------------

int main() {
  //
  fellow f1 = {
    .ident = {
      .lastname = "DiCaprio",
      .firstname = "Leonardo",
      .gndr = male,
      .dbirth = date_initialization(11, november, 1974)
    },
    .stts = single,
  };
  fellow f2 = {
    .ident = {
      .lastname = "Obama",
      .firstname = "Barack",
      .gndr = male,
      .dbirth = date_initialization(4, august, 1961)
    },
    .stts = married,
    .u = {
      .spouse = {
        .ident = {
          .lastname = "Obama",
          .firstname = "Michelle",
          .gndr = female,
          .dbirth = date_initialization(17, january, 1964)
        },
        .dspouse = date_initialization(3, october, 1992)
      }
    }
  };
  //
  date d = date_initialization(31, january, 2022);
  //
  fellow_print_reminder(&f1, d);
  fellow_print_reminder(&f2, d);
  //
  return EXIT_SUCCESS;
}

//--- date : implantation ------------------------------------------------------

//  is_leap_year : renvoie true ou false selon que l'année n est bissextile ou
//    non.
bool is_leap_year(int n) {
  return n % 4 == 0 && (n % 100 != 0 || n % 400 == 0);
}

date date_initialization(int day, int month, int year) {
  assert(year >= YEAR_MIN && year <= YEAR_MAX);
  assert(month >= MONTH_MIN && month <= MONTH_MAX);
  assert(day >= DAY_MIN && day <= daymax[is_leap_year(year)][month]);
  return
    (date) {
      .day = (uint8_t) day,
      .month = (uint8_t) month,
      .year = (uint16_t) year,
    };
}

bool date_is_anniversary(date dcalendar, date dreference) {
  if (dcalendar.month != dreference.month) {
    return false;
  }
  if (dcalendar.day == dreference.day) {
    return true;
  }
  return
    dcalendar.month == february
    && dcalendar.day == daymax[false][february]
    && dreference.day == daymax[true][february]
    && !is_leap_year(dcalendar.year);
}

//--- fellow : implantation ----------------------------------------------------

void identity_print_title_name(const identity *idptr) {
  const char *title[] = {
    [male] = "M.",
    [female] = "Mme",
    [other] = "",
  };
  printf("%s%s%s %s",
      title[idptr->gndr],
      *(title[idptr->gndr]) == '\0' ? "" : " ",
      idptr->firstname,
      idptr->lastname);
}

void fellow_print_reminder(const fellow *flwptr, date d) {
  const char *partner[] = {
    [male] = "conjoint",
    [female] = "conjointe",
    [other] = "conjoint⋅e",
  };
  printf("Bonjour ");
  identity_print_title_name(&flwptr->ident);
  switch (flwptr->stts) {
    case married:
    case civilunion:
      if (date_is_anniversary(d, flwptr->u.spouse.ident.dbirth)) {
        printf(",\n"
            "Pensez à souhaiter ce jour\n"
            "l'anniversaire de votre %s,\n",
            partner[flwptr->u.spouse.ident.gndr]);
        identity_print_title_name(&flwptr->u.spouse.ident);
      }
      break;
    default:
      break;
  }
  printf(".\n"
      "Votre dévoué Big Brother\n"
      "\n");
}
