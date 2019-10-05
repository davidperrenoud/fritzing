// This file was generated by qlalr - DO NOT EDIT!

/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-08 Fritzing

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************/

#include <QDebug>
#include "gedaelementparser.h"
#include "gedaelementlexer.h"

GedaElementParser::GedaElementParser() :
    m_tos(0)
{
}

QVector<QVariant> & GedaElementParser::symStack() {
	return m_symStack;
}

void GedaElementParser::reallocateStack()
{
	int size = m_stateStack.size();
	if (size == 0)
		size = 128;
	else
		size <<= 1;

	m_stateStack.resize(size);
}

QString GedaElementParser::errorMessage() const noexcept
{
	return m_errorMessage;
}

QVariant GedaElementParser::result() const noexcept
{
	return m_result;
}

bool GedaElementParser::parse(GedaElementLexer *lexer)
{
	constexpr int INITIAL_STATE = 0;

	int yytoken = -1;

	reallocateStack();

	m_tos = 0;
	m_stateStack[++m_tos] = INITIAL_STATE;

	while (true) {
		const int state = m_stateStack.at(m_tos);
		if (yytoken == -1 && - TERMINAL_COUNT != action_index [state])
			yytoken = lexer->lex();
		int act = t_action (state, yytoken);
		if (act == ACCEPT_STATE)
			return true;

		else if (act > 0) {
			if (++m_tos == m_stateStack.size())
				reallocateStack();
			m_stateStack[m_tos] = act;
			yytoken = -1;
		} else if (act < 0) {
			int r = - act - 1;

			m_tos -= rhs [r];
			act = m_stateStack.at(m_tos++);

			switch (r) {
			case 0: {
				//qDebug() << "got geda_element ";
			} break;
			case 2: {
			} break;
			case 3: {
				m_symStack.append(QChar(')'));
			}
			break;
			case 4: {
				m_symStack.append(QChar(']'));
			}
			break;
			case 6: {
				//qDebug() << "    got element_command sequence ";
			} break;
			case 7: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got element_command sequence ";
			}
			break;
			case 8: {
				m_symStack.append(QChar(']'));
				//qDebug() << "    got element_command sequence ";
			}
			break;
			case 9: {
				//qDebug() << "    got element_arguments ";
			} break;
			case 11: {
				//qDebug() << "    got sub_element_groups ";
			} break;
			case 17: {
				//qDebug() << "    got sub_element_group ";
			} break;
			case 18: {
				//qDebug() << "got mark_element ";
			} break;
			case 20: {
				//qDebug() << "    got mark_sequence ";
			} break;
			case 21: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got mark_paren_sequence ";
			}
			break;
			case 22: {
				m_symStack.append(QChar(']'));
				//qDebug() << "    got mark_bracket_sequence ";
			}
			break;
			case 23: {
				//qDebug() << "    got mark_arguments";
			} break;
			case 24: {
				//qDebug() << "got pin_element ";
			} break;
			case 26: {
				//qDebug() << "    got pin_sequence ";
			} break;
			case 27: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got pin_paren_sequence ";
			}
			break;
			case 28: {
				m_symStack.append(QChar(']'));
				//qDebug() << "    got pin_bracket_sequence ";
			}
			break;
			case 32: {
				//qDebug() << "    got pin_arguments ";
			} break;
			case 33: {
				//qDebug() << "    got pin_arguments 1";
			} break;
			case 34: {
				//qDebug() << "    got pin_arguments 2";
			} break;
			case 35: {
				//qDebug() << "    got pin_arguments 3";
			} break;
			case 36: {
				//qDebug() << "    got pin_arguments 4 ";
			} break;
			case 37: {
				//qDebug() << "got pad_element ";
			} break;
			case 39: {
				//qDebug() << "    got pad_sequence ";
			} break;
			case 40: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got pad_paren_sequence ";
			}
			break;
			case 41: {
				m_symStack.append(QChar(']'));
				//qDebug() << "    got pad_bracket_sequence ";
			}
			break;
			case 44: {
				//qDebug() << "    got pad_arguments ";
			} break;
			case 45: {
				//qDebug() << "    got pad_arguments 1";
			} break;
			case 46: {
				//qDebug() << "    got pad_arguments 2";
			} break;
			case 47: {
				//qDebug() << "    got pad_arguments 3";
			} break;
			case 48: {
				//qDebug() << "got element_line_element ";
			} break;
			case 50: {
				//qDebug() << "    got element_line_sequence ";
			} break;
			case 51: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got element_line_paren_sequence ";
			}
			break;
			case 52: {
				m_symStack.append(QChar(']'));
				//qDebug() << "    got element_line_bracket_sequence ";
			}
			break;
			case 53: {
				//qDebug() << "    got element_line_arguments ";
			} break;
			case 54: {
				//qDebug() << "got element_arc_element ";
			} break;
			case 56: {
				//qDebug() << "    got element_arc_sequence ";
			} break;
			case 57: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got element_arc_paren_sequence ";
			}
			break;
			case 58: {
				m_symStack.append(QChar(']'));
				//qDebug() << "    got element_arc_bracket_sequence ";
			}
			break;
			case 59: {
				//qDebug() << "    got element_arc_arguments ";
			} break;
			case 60: {
				//qDebug() << "got attribute_element ";
			} break;
			case 61: {
				//qDebug() << "    got attribute_sequence ";
			} break;
			case 62: {
				m_symStack.append(QChar(')'));
				//qDebug() << "    got attribute_paren_sequence ";
			}
			break;
			case 63: {
				//qDebug() << "    got attribute_arguments ";
			} break;
			case 64: {
			} break;
			case 65: {
			} break;
			case 66: {
			} break;
			case 67: {
			} break;
			case 68: {
			} break;
			case 69: {
			} break;
			case 70: {
			} break;
			case 71: {
			} break;
			case 72: {
			} break;
			case 73: {
			} break;
			case 74: {
			} break;
			case 75: {
			} break;
			case 76: {
			} break;
			case 77: {
			} break;
			case 78: {
			} break;
			case 79: {
			} break;
			case 80: {
			} break;
			case 82: {
			} break;
			case 83: {
			} break;
			case 84: {
			} break;
			case 85: {
			} break;
			case 86: {
			} break;
			case 87: {
			} break;
			case 88: {
			} break;
			case 89: {
			} break;
			case 90: {
			} break;
			case 91: {
			} break;
			case 92: {
			} break;
			case 93: {
				//qDebug() << "        got NUMBER " << lexer->currentNumber();
				m_symStack.append(lexer->currentNumber());
			}
			break;

			case 94: {
				//qDebug() << "        got HEXNUMBER " << lexer->currentNumber();
				m_symStack.append(lexer->currentNumber());
			}
			break;

			case 95: {
				//qDebug() << "        got STRING " << lexer->currentString();
				m_symStack.append(lexer->currentString());
			}
			break;

			case 96: {
				//qDebug() << "got ELEMENT command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			case 97: {
				//qDebug() << "got PIN command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			case 98: {
				//qDebug() << "got PAD command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			case 99: {
				//qDebug() << "got MARK command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			case 100: {
				//qDebug() << "got ELEMENTLINE command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			case 101: {
				//qDebug() << "got ELEMENTARC command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			case 102: {
				//qDebug() << "got ATTRIBUTE command ";
				m_symStack.append(lexer->currentCommand());
			}
			break;

			} // switch

			m_stateStack[m_tos] = nt_action(act, lhs[r] - TERMINAL_COUNT);

		} else {
			int ers = state;
			int shifts = 0;
			int reduces = 0;
			int expected_tokens[3];
			for (int tk = 0; tk < TERMINAL_COUNT; ++tk) {
				int k = t_action(ers, tk);

				if (! k)
					continue;
				else if (k < 0)
					++reduces;
				else if (spell[tk]) {
					if (shifts < 3)
						expected_tokens[shifts] = tk;
					++shifts;
				}
			}

			m_errorMessage.clear();
			if (shifts && shifts < 3) {
				bool first = true;

				for (int s = 0; s < shifts; ++s) {
					if (first)
						m_errorMessage += QLatin1String("Expected ");
					else
						m_errorMessage += QLatin1String(", ");

					first = false;
					m_errorMessage += QLatin1String("`");
					m_errorMessage += QLatin1String(spell[expected_tokens[s]]);
					m_errorMessage += QLatin1String("'");
				}
			}

			return false;
		}
	}

	return false;
}
