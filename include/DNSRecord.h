#ifndef DNS_RECORD_H
#define DNS_RECORD_H
#include <string> 
#include <string_view>
#include "DNSTypes.h"
// Should never include DNSDatabase.h
//Represents one DNS Resource record

class DNSRecord
{
    public:
        DNSRecord(
            dns::DomainName domain,
            dns::RecordType type,
            std::string value,
            dns::TTL ttl = dns::DefaultTTL
        );

        [[nodiscard]]
        std::string_view domain() const noexcept;

        [[nodiscard]]
        dns::RecordType type() const noexcept;

        [[nodiscard]]
        std::string_view value() const noexcept;

        [[nodiscard]]
        dns::TTL ttl() const noexcept;

        void setTTL(dns::TTL ttl);

        [[nodiscard]]
        bool matches(std::string_view domain) const noexcept;
    
    private:
        dns::DomainName domain_;
        dns::RecordType type_;
        dns::RecordValue value_;
        dns::TTL ttl_;
};

#endif