#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT mvpregister : public eosio::contract {

  public:
    using contract::contract;

    mvpregister(
      name receiver,
      name code,
      datastream<const char*> ds
    ): contract(receiver, code, ds) {}

    ACTION reg( const name user ) {
      require_auth( user );
    }

  private:
    TABLE move {
      uint128_t prim_key;
      name owner;

      uint128_t primary_key() const { return prim_key;}
    };

    typedef eosio::multi_index<"moves"_n, move> move_index;
};

EOSIO_DISPATCH( mvpregister, (reg) )
