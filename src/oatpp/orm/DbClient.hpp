/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_orm_DbClient_hpp
#define oatpp_orm_DbClient_hpp

#include "Executor.hpp"
#include "Transaction.hpp"

#include "oatpp/core/data/stream/Stream.hpp"
#include "oatpp/core/data/mapping/type/Type.hpp"
#include "oatpp/core/Types.hpp"

#include <unordered_map>

namespace oatpp { namespace orm {

/**
 * Database client.
 */
class DbClient {
private:
  typedef oatpp::data::mapping::type::Type Type;
protected:
  std::shared_ptr<Executor> m_executor;
public:

  /**
   * Constructor.
   * @param executor - &id:oatpp::orm::Executor;.
   */
  DbClient(const std::shared_ptr<Executor>& executor);

  /**
   * Virtual destructor.
   */
  virtual ~DbClient() = default;

  /**
   * Get database connection.
   * @return
   */
  std::shared_ptr<Connection> getConnection();

  /**
   * Execute arbitrary query.
   * @param query - query text.
   * @param params - query parameters.
   * @param connection - database connection.
   * @return - &id:oatpp::orm::QueryResult;.
   */
  std::shared_ptr<QueryResult> executeQuery(const oatpp::String& query,
                                            const std::unordered_map<oatpp::String, oatpp::Void>& params,
                                            const std::shared_ptr<Connection>& connection = nullptr);

  /**
   * Begin database transaction.
   * @param connection - database connection.
   * @return - &id:oatpp::orm::Transaction;.
   */
  Transaction beginTransaction(const std::shared_ptr<Connection>& connection = nullptr);

};

}}

#endif // oatpp_orm_DbClient_hpp
