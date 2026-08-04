#include <string_view>
#include <filesystem>
#include <unordered_map>
#include <optional>

#include "DNSTypes.h"
#include "DNSRecord.h"
// Should never include DNSServer.h
// Enforcing acyclic dependencies
namespace dns
{
    class DNSDatabase
    {
        public:
            DNSDatabase() = default;

            [[nodiscard]]
            bool addRecord(const DNSRecord& record);

            [[nodiscard]]
            bool removeRecord(std::string_view domain);

            [[nodiscard]]
            std::optional<DNSRecord> findRecord(std::string_view domain) const;

            [[nodiscard]]
            bool contains(std::string_view domain) const noexcept;


            void clear() noexcept;

            [[nodiscard]]
            std::size_t size() const noexcept;

            [[nodiscard]]
            bool empty() const noexcept;

            [[nodiscard]]
            bool loadFromFile(const std::filesystem::path& file);

            [[nodiscard]]
            bool saveToFile(const std::filesystem::path& file) const;

        private:

            std::unordered_map<dns::DomainName, DNSRecord> records_;
    };

}
