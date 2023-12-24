add_library(Ticket STATIC)
target_sources(Ticket
	PRIVATE Ticket.cpp TicketDialog.cpp
	PUBLIC Ticket.hpp TicketDialog.hpp)
target_include_directories(Ticket
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Ticket
    PUBLIC Qt::Widgets)
