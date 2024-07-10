constexpr auto operator<=> (const Array &other) const noexcept {
        for(int i = 0; i < N; ++i) {
            if(m_data[i] > other.m_data[i]) return 1;
            else if(m_data[i] < other.m_data[i]) return -1;
        }
        return 0;
    }