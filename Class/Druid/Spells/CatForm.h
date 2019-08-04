#pragma once

#include "Spell.h"
#include "TalentRequirer.h"

class Buff;
class Druid;

class CatForm: public Spell, public TalentRequirer {
public:
    CatForm(Character* pchar, Buff* cat_form);
    ~CatForm() override;

private:
    friend class Druid;

    Druid* druid;
    Buff* buff;
    unsigned base_resource_cost;

    const QVector<double> natural_shapeshifter_ranks {1.0, 0.9, 0.8, 0.7};

    SpellStatus is_ready_spell_specific() const override;
    void spell_effect() override;

    void increase_talent_rank_effect(const QString& talent_name, const int curr) override;
    void decrease_talent_rank_effect(const QString& talent_name, const int curr) override;
};
