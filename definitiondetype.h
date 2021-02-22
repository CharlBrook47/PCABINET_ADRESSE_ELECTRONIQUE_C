#ifndef DEFINITIONDETYPE
#define DEFINITIONDETYPE

struct type_personne
{
    int id;
    const gchar *nom,*prenom,*contact,*adresse, *email;
};
typedef struct type_personne personne;

struct type_client
{
    int id;
    const gchar *nom,*prenom,*contact;
};
typedef struct type_client client;

/*enum
{
    COL_ID,
    COL_NOM,
    COL_PRENOM,
    COL_CONTACT,
    COL_ADRESSE
};*/

#endif // TYPEDEF_H_INCLUDED
