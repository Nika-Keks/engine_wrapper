#pragma once

template<size_t ... Indices> struct PackIndices {
	typedef PackIndices<Indices..., sizeof ... (Indices)> next;
};

template<size_t N> struct CreatePackIndices {
	typedef typename CreatePackIndices<N - 1>::type::next type;
};

template<> struct CreatePackIndices<0> {
	typedef PackIndices<> type;
};
