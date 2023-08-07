#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// Change th3e following variables according to your database configuration
std::string host = "localhost";
std::string user = "root";
std::string password = "2oo3_@J3rb0?72i89a5a.BUddY";
std::string database = "ps_db";

int test() {
	return 5;
}


#pragma once

namespace FormTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();

			try {
				sql::mysql::MySQL_Driver* driver;
				sql::Connection* con;
				sql::Statement* stmt;
				sql::ResultSet* res;

				// Create a MySQL connection
				driver = sql::mysql::get_mysql_driver_instance();
				con = driver->connect(host, user, password);

				// Connect to the database
				con->setSchema(database);

				// Execute a query and fetch data
				stmt = con->createStatement();
				res = stmt->executeQuery("SHOW TABLES");

				// Display the data in the console
				int row = 0;
				while (res->next()) {
					Button^ button = gcnew Button();
					button->Text = msclr::interop::marshal_as<String^>((res->getString(1)).c_str());
					button->Dock = DockStyle::Fill;
					button->Click += gcnew EventHandler(this, &MyForm::displayTable);
					this->menuTablas->Controls->Add(button, 0, row);
					row++;
					displayTable((res->getString(1)).c_str());
				}

				delete res;
				delete stmt;
				delete con;
			} catch (sql::SQLException& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ tableView;
	private: System::Windows::Forms::Label^ LblTabla;
	private: System::Windows::Forms::TableLayoutPanel^ menuTablas;
	private: System::Windows::Forms::Label^ LblEmpresa;
	private: System::Windows::Forms::Button^ BtnCerrar;
	private: System::Windows::Forms::Panel^ leftPanel;
	private: System::Windows::Forms::Panel^ bottomPanel;


	private: System::Windows::Forms::Button^ BtnNuevo;
	private: System::Windows::Forms::Button^ BtnEditar;
	private: System::Windows::Forms::Button^ BtnBorrar;






	private: System::Windows::Forms::Button^ BtnGuardar;
	private: System::Windows::Forms::Label^ LblTitleID;
	private: System::Windows::Forms::Label^ LblID;

	private: System::Windows::Forms::Panel^ topPanel;
	private: System::Windows::Forms::TableLayoutPanel^ camposTabla;




	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableView = (gcnew System::Windows::Forms::DataGridView());
			this->LblTabla = (gcnew System::Windows::Forms::Label());
			this->menuTablas = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->LblEmpresa = (gcnew System::Windows::Forms::Label());
			this->BtnCerrar = (gcnew System::Windows::Forms::Button());
			this->leftPanel = (gcnew System::Windows::Forms::Panel());
			this->bottomPanel = (gcnew System::Windows::Forms::Panel());
			this->BtnNuevo = (gcnew System::Windows::Forms::Button());
			this->BtnEditar = (gcnew System::Windows::Forms::Button());
			this->BtnBorrar = (gcnew System::Windows::Forms::Button());
			this->BtnGuardar = (gcnew System::Windows::Forms::Button());
			this->LblTitleID = (gcnew System::Windows::Forms::Label());
			this->LblID = (gcnew System::Windows::Forms::Label());
			this->topPanel = (gcnew System::Windows::Forms::Panel());
			this->camposTabla = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableView))->BeginInit();
			this->topPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableView
			// 
			this->tableView->AllowUserToAddRows = false;
			this->tableView->AllowUserToDeleteRows = false;
			this->tableView->AllowUserToResizeColumns = false;
			this->tableView->AllowUserToResizeRows = false;
			this->tableView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->tableView->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->tableView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tableView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->tableView->Location = System::Drawing::Point(450, 325);
			this->tableView->Name = L"tableView";
			this->tableView->ReadOnly = true;
			this->tableView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->tableView->Size = System::Drawing::Size(700, 325);
			this->tableView->TabIndex = 3;
			this->tableView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::tableView_CellContentClick);
			// 
			// LblTabla
			// 
			this->LblTabla->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblTabla->Location = System::Drawing::Point(650, 40);
			this->LblTabla->Name = L"LblTabla";
			this->LblTabla->Size = System::Drawing::Size(300, 25);
			this->LblTabla->TabIndex = 5;
			this->LblTabla->Text = L"Nombre Tabla";
			this->LblTabla->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// menuTablas
			// 
			this->menuTablas->ColumnCount = 1;
			this->menuTablas->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->menuTablas->Location = System::Drawing::Point(40, 100);
			this->menuTablas->Name = L"menuTablas";
			this->menuTablas->RowCount = 5;
			this->menuTablas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->menuTablas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->menuTablas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->menuTablas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->menuTablas->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->menuTablas->Size = System::Drawing::Size(320, 450);
			this->menuTablas->TabIndex = 6;
			// 
			// LblEmpresa
			// 
			this->LblEmpresa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblEmpresa->Location = System::Drawing::Point(100, 40);
			this->LblEmpresa->Name = L"LblEmpresa";
			this->LblEmpresa->Size = System::Drawing::Size(200, 25);
			this->LblEmpresa->TabIndex = 7;
			this->LblEmpresa->Text = L"Nombre Empresa";
			this->LblEmpresa->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// BtnCerrar
			// 
			this->BtnCerrar->Location = System::Drawing::Point(100, 580);
			this->BtnCerrar->Name = L"BtnCerrar";
			this->BtnCerrar->Size = System::Drawing::Size(200, 45);
			this->BtnCerrar->TabIndex = 8;
			this->BtnCerrar->Text = L"SALIR";
			this->BtnCerrar->UseVisualStyleBackColor = true;
			this->BtnCerrar->Click += gcnew System::EventHandler(this, &MyForm::BtnCerrar_Click);
			// 
			// leftPanel
			// 
			this->leftPanel->Location = System::Drawing::Point(0, 0);
			this->leftPanel->Name = L"leftPanel";
			this->leftPanel->Size = System::Drawing::Size(400, 675);
			this->leftPanel->TabIndex = 1;
			// 
			// bottomPanel
			// 
			this->bottomPanel->Location = System::Drawing::Point(400, 300);
			this->bottomPanel->Name = L"bottomPanel";
			this->bottomPanel->Size = System::Drawing::Size(800, 375);
			this->bottomPanel->TabIndex = 9;
			// 
			// BtnNuevo
			// 
			this->BtnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnNuevo->Location = System::Drawing::Point(50, 100);
			this->BtnNuevo->Name = L"BtnNuevo";
			this->BtnNuevo->Size = System::Drawing::Size(150, 40);
			this->BtnNuevo->TabIndex = 10;
			this->BtnNuevo->Text = L"Nuevo";
			this->BtnNuevo->UseVisualStyleBackColor = true;
			this->BtnNuevo->Click += gcnew System::EventHandler(this, &MyForm::BtnNuevo_Click);
			// 
			// BtnEditar
			// 
			this->BtnEditar->Enabled = false;
			this->BtnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnEditar->Location = System::Drawing::Point(50, 150);
			this->BtnEditar->Name = L"BtnEditar";
			this->BtnEditar->Size = System::Drawing::Size(150, 40);
			this->BtnEditar->TabIndex = 11;
			this->BtnEditar->Text = L"Editar";
			this->BtnEditar->UseVisualStyleBackColor = true;
			this->BtnEditar->Click += gcnew System::EventHandler(this, &MyForm::BtnEditar_Click);
			// 
			// BtnBorrar
			// 
			this->BtnBorrar->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->BtnBorrar->Enabled = false;
			this->BtnBorrar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnBorrar->Location = System::Drawing::Point(50, 200);
			this->BtnBorrar->Name = L"BtnBorrar";
			this->BtnBorrar->Size = System::Drawing::Size(150, 40);
			this->BtnBorrar->TabIndex = 12;
			this->BtnBorrar->Text = L"Borrar";
			this->BtnBorrar->UseVisualStyleBackColor = true;
			this->BtnBorrar->Click += gcnew System::EventHandler(this, &MyForm::BtnBorrar_Click);
			// 
			// BtnGuardar
			// 
			this->BtnGuardar->Enabled = false;
			this->BtnGuardar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnGuardar->Location = System::Drawing::Point(475, 250);
			this->BtnGuardar->Name = L"BtnGuardar";
			this->BtnGuardar->Size = System::Drawing::Size(150, 40);
			this->BtnGuardar->TabIndex = 20;
			this->BtnGuardar->Text = L"Guardar";
			this->BtnGuardar->UseVisualStyleBackColor = true;
			this->BtnGuardar->Click += gcnew System::EventHandler(this, &MyForm::BtnGuardar_Click);
			// 
			// LblTitleID
			// 
			this->LblTitleID->Location = System::Drawing::Point(1040, 80);
			this->LblTitleID->Name = L"LblTitleID";
			this->LblTitleID->Size = System::Drawing::Size(20, 15);
			this->LblTitleID->TabIndex = 21;
			this->LblTitleID->Text = L"ID:";
			this->LblTitleID->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// LblID
			// 
			this->LblID->Location = System::Drawing::Point(1070, 80);
			this->LblID->Name = L"LblID";
			this->LblID->Size = System::Drawing::Size(80, 15);
			this->LblID->TabIndex = 22;
			this->LblID->Text = L"#id";
			this->LblID->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// topPanel
			// 
			this->topPanel->Controls->Add(this->camposTabla);
			this->topPanel->Controls->Add(this->BtnNuevo);
			this->topPanel->Controls->Add(this->BtnGuardar);
			this->topPanel->Controls->Add(this->BtnEditar);
			this->topPanel->Controls->Add(this->BtnBorrar);
			this->topPanel->Location = System::Drawing::Point(400, 0);
			this->topPanel->Name = L"topPanel";
			this->topPanel->Size = System::Drawing::Size(800, 300);
			this->topPanel->TabIndex = 23;
			// 
			// camposTabla
			// 
			this->camposTabla->ColumnCount = 2;
			this->camposTabla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->camposTabla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->camposTabla->Location = System::Drawing::Point(240, 100);
			this->camposTabla->Name = L"camposTabla";
			this->camposTabla->RowCount = 3;
			this->camposTabla->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33)));
			this->camposTabla->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33)));
			this->camposTabla->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34)));
			this->camposTabla->Size = System::Drawing::Size(500, 145);
			this->camposTabla->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 675);
			this->Controls->Add(this->LblID);
			this->Controls->Add(this->LblTitleID);
			this->Controls->Add(this->LblEmpresa);
			this->Controls->Add(this->menuTablas);
			this->Controls->Add(this->LblTabla);
			this->Controls->Add(this->tableView);
			this->Controls->Add(this->BtnCerrar);
			this->Controls->Add(this->leftPanel);
			this->Controls->Add(this->bottomPanel);
			this->Controls->Add(this->topPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tableView))->EndInit();
			this->topPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	void displayTable(std::string tableName) {
		this->BtnEditar->Enabled = false;
		this->BtnBorrar->Enabled = false;
		this->BtnGuardar->Enabled = false;

		this->LblTabla->Text = msclr::interop::marshal_as<System::String^>("Tabla: "+tableName);
		try {
			sql::mysql::MySQL_Driver* driver;
			sql::Connection* con;
			sql::Statement* stmt;
			sql::ResultSet* res;

			// Create a MySQL connection
			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(host, user, password);

			// Connect to the database
			con->setSchema(database);

			// Execute a query and fetch data
			stmt = con->createStatement();
			const char* query = (std::string("SELECT * FROM ") + tableName).c_str();
			res = stmt->executeQuery(query);

			// Get the metadata to obtain column names
			sql::ResultSetMetaData* meta = res->getMetaData();
			int numColumns = meta->getColumnCount();
			this->tableView->ColumnCount = numColumns;

			this->camposTabla->Controls->Clear();
			this->camposTabla->ColumnCount = 2;
			this->camposTabla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->camposTabla->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->camposTabla->RowCount = numColumns-1;
			for (int row = 0; row < this->camposTabla->RowCount; row++) {
				this->camposTabla->RowStyles->Add(gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100.0f / this->camposTabla->RowCount));
			}
			// Set column names
			for (int i = 0; i < numColumns; i++) {
				String^ colName = msclr::interop::marshal_as<System::String^>(meta->getColumnName(i + 1).c_str());
				this->tableView->Columns[i]->Name = colName;
				this->tableView->Columns[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

				if (i == 0) continue;

				Label^ LblCampo = gcnew Label();
				LblCampo->Text = colName;
				LblCampo->Dock = DockStyle::Fill;
				this->camposTabla->Controls->Add(LblCampo, 0, i);

				TextBox^ textBoxCampo = gcnew TextBox();
				textBoxCampo->Enabled = false;
				textBoxCampo->Dock = DockStyle::Fill;
				this->camposTabla->Controls->Add(textBoxCampo, 1, i);
			}
			// Fill DataGridView
			this->tableView->Rows->Clear();
			while (res->next()) {
				array<String^>^ newRow = gcnew array<String^>(numColumns);
				for (int i = 0; i < numColumns; i++) {
					newRow[i] = msclr::interop::marshal_as<System::String^>(res->getString(meta->getColumnName(i + 1).c_str()).c_str());
				}
				this->tableView->Rows->Add(newRow);
			}

			delete res;
			delete stmt;
			delete con;
		} catch (sql::SQLException& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	void displayTable(Object^ sender, EventArgs^ e) {
		Button^ clickedButton = dynamic_cast<Button^>(sender);
		String^ selectedItem = clickedButton->Text->ToString();
		displayTable(msclr::interop::marshal_as<std::string>(selectedItem));
	}

	private: System::Void BtnCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	void registroSeleccionado(int row) {
		this->BtnEditar->Enabled = true;
		this->BtnBorrar->Enabled = true;

		this->LblID->Text = this->tableView->Rows[row]->Cells[0]->Value->ToString();

		this->tableView->Rows[row]->Selected = true;
		int col = 1;
		for each (Control ^ control in this->camposTabla->Controls) {
			TextBox^ textBox = dynamic_cast<TextBox^>(control);
			if (textBox != nullptr) {
				textBox->Text = this->tableView->Rows[row]->Cells[col]->Value->ToString();
				textBox->Enabled = false;
				col++;
			}
		}
	}

	private: System::Void tableView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		registroSeleccionado(e->RowIndex);
	}

	private: System::Void tableView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		registroSeleccionado(e->RowIndex);
	}

	private: System::Void BtnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		this->menuTablas->Enabled = false;
		this->tableView->Enabled = false;

		this->BtnNuevo->Enabled = false;
		this->BtnEditar->Enabled = false;
		this->BtnBorrar->Enabled = false;
		this->BtnGuardar->Enabled = true;

		this->LblID->Text = msclr::interop::marshal_as<System::String^>("0");
		for each (Control ^ control in this->camposTabla->Controls) {
			TextBox^ textBox = dynamic_cast<TextBox^>(control);
			if (textBox != nullptr) {
				textBox->Text = "";
				textBox->Enabled = true;
			}
		}
	}

	private: System::Void BtnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->menuTablas->Enabled = false;
		this->tableView->Enabled = false;

		this->BtnNuevo->Enabled = false;
		this->BtnEditar->Enabled = false;
		this->BtnBorrar->Enabled = false;
		this->BtnGuardar->Enabled = true;
	}

	private: System::Void BtnBorrar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ message = "¿Seguro que desea eliminar el registro?";
		String^ caption = "Alerta";
		MessageBoxButtons buttons = MessageBoxButtons::OKCancel;
		MessageBoxIcon icon = MessageBoxIcon::Warning;

		System::Windows::Forms::DialogResult result = MessageBox::Show(this, message, caption, buttons, icon);

		if (result == System::Windows::Forms::DialogResult::OK) {
			std::string tableName = msclr::interop::marshal_as<std::string>(this->LblTabla->Text).substr(7);
			int id = Int32::Parse(this->LblID->Text);
			try {
				sql::mysql::MySQL_Driver* driver;
				sql::Connection* con;
				sql::Statement* stmt;
				sql::ResultSet* res;

				// Create a MySQL connection
				driver = sql::mysql::get_mysql_driver_instance();
				con = driver->connect(host, user, password);

				// Connect to the database
				con->setSchema(database);

				// Execute a query and fetch data
				stmt = con->createStatement();
				const char* query = (std::string("DELETE * FROM ") + tableName +
					std::string("WHERE ") +
					msclr::interop::marshal_as<std::string>(this->tableView->Columns[0]->HeaderText) +
					std::string(" = ") + std::to_string(id)
				).c_str();
				res = stmt->executeQuery(query);

				delete res;
				delete stmt;
				delete con;
			} catch (sql::SQLException& e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
			displayTable(tableName);
		}
	}

	private: System::Void BtnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string tableName = msclr::interop::marshal_as<std::string>(this->LblTabla->Text).substr(7);
		int id = Int32::Parse(this->LblID->Text);
		if (id == 0) nuevoRegistro();
		else actualizarRegistro()
		try {
			sql::mysql::MySQL_Driver* driver;
			sql::Connection* con;
			sql::Statement* stmt;
			sql::ResultSet* res;

			// Create a MySQL connection
			driver = sql::mysql::get_mysql_driver_instance();
			con = driver->connect(host, user, password);

			// Connect to the database
			con->setSchema(database);

			// Execute a query and fetch data
			array<String^>^ headerArray = gcnew array<String^>(this->tableView->Columns->Count);
			for (int i = 1; i < this->tableView->Columns->Count; i++) {
				headerArray[i-1] = this->tableView->Columns[i]->HeaderText;
			}
			String^ headers = String::Join(", ", headerArray);
			array<String^>^ valueArray = gcnew array<String^>(this->tableView->Columns->Count);
			int i = 0;
			for each (Control ^ control in this->camposTabla->Controls) {
				TextBox^ textBox = dynamic_cast<TextBox^>(control);
				if (textBox != nullptr) {
					valueArray[i] = textBox->Text;
					i++;
				}
			}
			String^ values = String::Join(", ", valueArray);
			stmt = con->createStatement();
			const char* query = (std::string("INSERT INTO ") + tableName + std::string(" (") +
				msclr::interop::marshal_as<std::string>(headerArray) + std::string(") VALUES (") +
				msclr::interop::marshal_as<std::string>(values) + std::string(");")
				).c_str();
			res = stmt->executeQuery(query);

			delete res;
			delete stmt;
			delete con;
		} catch (sql::SQLException& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		displayTable(tableName);
	}
};
}