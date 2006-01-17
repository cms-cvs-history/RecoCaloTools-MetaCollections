#ifndef RECOCALOTOOLS_METACOLLECTIONS_CALORECHITMETACOLLECTION_H
#define RECOCALOTOOLS_METACOLLECTIONS_CALORECHITMETACOLLECTION_H 1

#include "RecoCaloTools/MetaCollections/interface/CaloRecHitMetaCollectionV.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include <map>

class CaloRecHitMetaCollectionItem;

/** \class CaloRecHitMetaCollection
  *  
  * $Date: $
  * $Revision: $
  * \author J. Mans - Minnesota
  */
class CaloRecHitMetaCollection : public CaloRecHitMetaCollectionV {
public:
  typedef CaloRecHitMetaCollectionV::Iterator const_iterator;

  void add(const HBHERecHitCollection* hbhe);
  void add(const HORecHitCollection* ho);
  void add(const HFRecHitCollection* hf);

  virtual ~CaloRecHitMetaCollection();
  virtual const_iterator find(const DetId& id) const;
  virtual const CaloRecHit* at(const_iterator::offset_type i) const;
private:
  // This map is used for "at", and the key is the global index of the largest item in the list.
  std::map<int,CaloRecHitMetaCollectionItem*> m_items;
  std::multimap<int, CaloRecHitMetaCollectionItem*> m_findTool;
  int findIndex(const DetId& id) const;
};

#endif
