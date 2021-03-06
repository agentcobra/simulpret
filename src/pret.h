#ifndef PRET_H
#define PRET_H

#include <QList>
#include <QString>
#include <QDate>
#include "evenement.h"
#include "visitor.h"

// forward declaration to avoid recursion loop on included files
class Visitor;

class Pret
{
public:
    int id;
    long capitalEmprunte;
    int duree; // duree du pret en mois
    float mensualite;
    float tauxInteret;
    float tauxAssurance;
    QDate dateDebloquage;
    QList<Evenement> evenements;
public:
    Pret();
    Pret(long capitalEmprunte, float tauxInteret, int duree, float tauxAssurance, QDate dateDebloquage);
    Pret(long capitalEmprunte, float tauxInteret, float mensualiteHorsAssurance, float tauxAssurance, QDate dateDebloquage);
    void initialize(long capitalEmprunte, float tauxInteret, int duree, float mensualiteHorsAssurance, float tauxAssurance, QDate dateDebloquage);

    /**
     * Calculer la durée de remboursement à payer en fonction des paramètres donnés (dont mensualité).
     */
    int calculerDureeRemboursement(long capitalEmprunte, float tauxInteret, float mensualite, float tauxAssurance);

    /**
     * Calculer la mensualité à payer en fonction des paramètres donnés (dont durée).
     */
    float calculerMensualite(long capitalEmprunte, float tauxInteret, int duree, float tauxAssurance);

    /**
     * Calculer le coût total du crédit (inclue l'assurance).
     */
    float getCoutTotalCredit(int echeancierId);

    /**
     * @brief Récupérer le montant total des remboursements anticipés.
     */
    float getSommeRbtAnticipes();

    /**
     * Ajouter un evenement au prêt.
     */
    void ajouterEvenement(Evenement *evt);

    /**
     * Récupérer l'identifiant du prêt.
     */
    int getId();

    /**
     * Positionner l'identifiant du prêt.
     */
    void setId(int id);

    long getCapitalEmprunte();
    float getTauxInteret();
    float getTauxAssurance();
    int getDuree();
    float getMensualite();
    QDate getDateDebloquage();

    /**
     * Afficher les informations principales du prêt.
     */
    QString toString();

    /** Pattern visiteur. */
    void accept(Visitor &visitor);
};

#endif // PRET_H
