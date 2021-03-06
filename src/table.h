#ifndef _AMQPP_TABLE_H_INCLUDED_
#define _AMQPP_TABLE_H_INCLUDED_

#include "export.h"

#include <boost/cstdint.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_variant.hpp>

#include <map>
#include <string>
#include <utility>

#ifdef _MSC_VER
# pragma warning ( push )
# pragma warning ( disable: 4251 )
#endif


namespace amqpp
{

class table_entry;

class AMQPP_EXPORT table
{
public:
  typedef std::map<const std::string, table_entry> table_impl_t;

  void insert(const table_entry& e);

  table_impl_t& get_map() { return m_table; }
  const table_impl_t& get_map() const { return m_table; }

  std::string to_string() const;
  uint32_t wireformat_size() const;

private:
  table_impl_t m_table;
};

} // namespace amqpp

#ifdef _MSC_VER
# pragma warning ( pop )
#endif

// Annoyingly because of the way the boost::recursive_varaiant_ works this
// Needs to be included here to make table used easily
#include "table_entry.h"

#endif // _AMQPP_TABLE_H_INCLUDED_
