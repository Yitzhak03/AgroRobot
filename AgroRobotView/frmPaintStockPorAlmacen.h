#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	// Agregar referencias a los modelos y controladores necesarios
	using namespace AgroRobotModel;
	using namespace AgroRobotController;
	using namespace System::Collections::Generic;

	/// <summary>
	/// frmPaintStockPorAlmacen - versión con formulario dinámico completo
	/// - Genera controles (GroupBox con Label, Button y barra de color proporcional) en panel1
	/// - Evita dibujar barras globales en panel1_Paint para que no haya solapamiento
	/// - Recalcula layout en Resize y Show
	/// </summary>
	public ref class frmPaintStockPorAlmacen : public System::Windows::Forms::Form {
	public:
		frmPaintStockPorAlmacen(void)
		{
			InitializeComponent();
		}
		frmPaintStockPorAlmacen(Almacen^ almacen, List<StockInsumo^>^ stocks)
		{
			InitializeComponent();
			this->almacenActual = almacen;
			this->listaStocks = stocks;
		}

	protected:
		~frmPaintStockPorAlmacen()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private:
		Almacen^ almacenActual;
		List<StockInsumo^>^ listaStocks;
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2 (leyenda)
			// 
			this->panel2->Location = System::Drawing::Point(220, 12);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(154, 166);
			this->panel2->TabIndex = 7;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmPaintStockPorAlmacen::panel2_Paint);
			// 
			// panel1 (contenedor dinámico)
			// 
			this->panel1->Location = System::Drawing::Point(11, 197);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(363, 507);
			this->panel1->TabIndex = 6;
			this->panel1->AutoScroll = true; // permitir scroll cuando hay muchos controles
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmPaintStockPorAlmacen::panel1_Paint);
			this->panel1->Resize += gcnew System::EventHandler(this, &frmPaintStockPorAlmacen::panel1_Resize);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(204, 167);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del almacén";
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(86, 103);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(95, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(86, 66);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(98, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(86, 30);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(98, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 106);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(61, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Ubicación: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 67);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 33);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id: ";
			// 
			// frmPaintStockPorAlmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(385, 729);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmPaintStockPorAlmacen";
			this->Text = L"Insumos por Almacén";
			this->Load += gcnew System::EventHandler(this, &frmPaintStockPorAlmacen::frmPaintStockPorAlmacen_Load);
			this->Shown += gcnew System::EventHandler(this, &frmPaintStockPorAlmacen::frmPaintStockPorAlmacen_Shown);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void frmPaintStockPorAlmacen_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// Cargar los datos del almacén en los TextBox
		if (this->almacenActual != nullptr) {
			this->textBox1->Text = this->almacenActual->Id.ToString();
			this->textBox2->Text = this->almacenActual->Nombre;
			this->textBox3->Text = this->almacenActual->Ubicacion;
		}
		// Si listaStocks se setea antes de Load, generamos la vista aquí (también la regeneramos en Shown para tamaño final)
		GenerateDynamicForm();
	}

	private: System::Void frmPaintStockPorAlmacen_Shown(System::Object^ sender, System::EventArgs^ e)
	{
		// Asegurar layout final cuando la ventana ya está mostrada y tamaños son definitivos
		GenerateDynamicForm();
	}

		   // Recalcular layout al cambiar tamaño del panel
	private: System::Void panel1_Resize(System::Object^ sender, System::EventArgs^ e)
	{
		GenerateDynamicForm();
	}

		   // Genera controles dinámicos en panel1 en función de listaStocks
	private: void GenerateDynamicForm()
	{
		// Limpiar controles previos
		this->panel1->Controls->Clear();

		if (this->listaStocks == nullptr || this->listaStocks->Count == 0) {
			return;
		}

		// Parámetros del layout de cada item
		int itemWidth = 170;   // ancho del GroupBox
		int itemHeight = 90;   // alto del GroupBox
		int spacingX = 12;
		int spacingY = 12;
		int marginLeft = 10;
		int marginTop = 10;

		// calcular cantidad de columnas según width real del panel (usar ClientSize para excluir scrollbars)
		int availableWidth = this->panel1->ClientSize.Width;
		if (availableWidth <= itemWidth) availableWidth = itemWidth + spacingX;
		int cols = Math::Max(1, (availableWidth + spacingX) / (itemWidth + spacingX));

		int x = marginLeft;
		int y = marginTop;
		int i = 0;

		for each (StockInsumo ^ stock in this->listaStocks) {
			// Crear un groupbox o panel para cada ítem
			GroupBox^ gb = gcnew GroupBox();
			gb->Size = System::Drawing::Size(itemWidth, itemHeight);
			gb->Location = System::Drawing::Point(x, y);
			gb->Text = ""; // dejamos sin título para más espacio
			gb->Tag = stock; // guardar referencia para handlers

			// Label con nombre (arriba)
			Label^ lbl = gcnew Label();
			lbl->AutoSize = false;
			lbl->Size = System::Drawing::Size(itemWidth - 90, 30);
			lbl->Location = System::Drawing::Point(8, 10);
			lbl->Text = stock->Insumoo->Nombre;
			lbl->Font = gcnew System::Drawing::Font("Arial", 9, FontStyle::Regular);
			gb->Controls->Add(lbl);

			// Botón de detalles (derecha)
			Button^ btn = gcnew Button();
			btn->Size = System::Drawing::Size(64, 24);
			btn->Location = System::Drawing::Point(itemWidth - 74, 10);
			btn->Text = "Detalles";
			// Asociar evento click
			btn->Click += gcnew EventHandler(this, &frmPaintStockPorAlmacen::OnDetalleClick);
			btn->Tag = stock;
			gb->Controls->Add(btn);

			// Barra de color proporcional (debajo)
			Panel^ colorBar = gcnew Panel();
			int barMaxWidth = itemWidth - 16; // margen izquierdo/derecho
			int barHeight = 14;
			int barX = 8;
			int barY = 45;

			// calcular porcentaje de llenado. Preferimos usar LimiteAlto si existe; si no, usar LimiteAlto como referencia.
			double cap = 0.0;
			try {
				// Si StockInsumo tiene LimiteAlto, úsala; si no, caerá al catch.
				cap = (double)stock->LimiteAlto;
			}
			catch (...) {
				cap = 0.0;
			}
			if (cap <= 0.0) {
				// fallback: usar LimiteAlto si existe
				cap = (double)stock->LimiteAlto;
			}
			double porcentaje = 0.0;
			if (cap > 0.0) {
				porcentaje = Math::Min(1.0, (double)stock->Stock / cap);
			} else {
				// si no hay referencia, mostrar barra según límites relativos
				if (stock->Stock == 0) porcentaje = 0.0;
				else if (stock->Stock < stock->LimiteBajo) porcentaje = 0.25;
				else if (stock->Stock < stock->LimiteAlto) porcentaje = 0.6;
				else porcentaje = 1.0;
			}
			int barWidth = (int)(barMaxWidth * porcentaje);
			if (barWidth < 2) barWidth = 2;

			colorBar->Location = System::Drawing::Point(barX, barY);
			colorBar->Size = System::Drawing::Size(barWidth, barHeight);
			colorBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			colorBar->Tag = stock;

			// color según niveles
			if (stock->Stock == 0) {
				colorBar->BackColor = Color::Red;
			} else if (stock->Stock < stock->LimiteBajo) {
				colorBar->BackColor = Color::Yellow;
			} else if (stock->Stock < stock->LimiteAlto) {
				colorBar->BackColor = Color::LightGreen;
			} else {
				colorBar->BackColor = Color::Green;
			}

			// Hacer clic en la barra también muestra detalles
			colorBar->Click += gcnew System::EventHandler(this, &frmPaintStockPorAlmacen::OnColorBarClick);

			gb->Controls->Add(colorBar);

			// Añadir una barra de fondo (marco) para representar el full width (opcional, para ver el máximo)
			Panel^ barBg = gcnew Panel();
			barBg->Location = System::Drawing::Point(barX, barY);
			barBg->Size = System::Drawing::Size(barMaxWidth, barHeight);
			barBg->BackColor = Color::Gainsboro;
			barBg->SendToBack(); // que quede detrás del colorBar
			gb->Controls->Add(barBg);
			barBg->SendToBack();

			// Información textual pequeña (porcentaje)
			Label^ lblPct = gcnew Label();
			lblPct->AutoSize = false;
			lblPct->Size = System::Drawing::Size(50, 16);
			lblPct->Location = System::Drawing::Point(8, barY + barHeight + 4);
			int pctInt = (int)(porcentaje * 100.0);
			lblPct->Text = String::Format("{0}%", pctInt);
			lblPct->Font = gcnew System::Drawing::Font("Arial", 8);
			gb->Controls->Add(lblPct);

			// Añadir el groupbox al panel
			this->panel1->Controls->Add(gb);

			// siguiente posición
			i++;
			if (i % cols == 0) {
				x = marginLeft;
				y += itemHeight + spacingY;
			} else {
				x += itemWidth + spacingX;
			}
		}
		// Forzar redibujado si es necesario
		this->panel1->Invalidate();
	}

		   // Mostrar detalles cuando se pulsa el botón Detalles
	private: System::Void OnDetalleClick(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ btn = safe_cast<Button^>(sender);
		StockInsumo^ stock = safe_cast<StockInsumo^>(btn->Tag);
		ShowStockDetails(stock);
	}

		   // Mostrar detalles al pulsar la barra de color
	private: System::Void OnColorBarClick(System::Object^ sender, System::EventArgs^ e)
	{
		Control^ ctl = safe_cast<Control^>(sender);
		StockInsumo^ stock = safe_cast<StockInsumo^>(ctl->Tag);
		ShowStockDetails(stock);
	}

		   // Ventana de detalles (ejemplo simple con MessageBox)
	private: void ShowStockDetails(StockInsumo^ stock)
	{
		if (stock == nullptr) return;
		String^ capStr = "N/A";
		try { capStr = stock->LimiteAlto.ToString(); }
		catch (...) { capStr = "N/A"; }

		String^ msg = String::Format("Insumo: {0}\nStock: {1}\nLimiteAlto: {2}\nLímite bajo: {3}\nLímite alto: {4}",
			(stock->Insumoo != nullptr ? stock->Insumoo->Nombre : "Sin nombre"),
			stock->Stock,
			capStr,
			stock->LimiteBajo,
			stock->LimiteAlto);
		MessageBox::Show(msg, "Detalles del stock", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

		   /// <summary>
		   /// Informacion de colores del panel2 (leyenda)
		   /// </summary>
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ graphics = e->Graphics;
		int y = 10;
		int separacionY = 30;
		// Verde oscuro
		Rectangle rectVerdeOscuro = Rectangle(10, y, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectVerdeOscuro);
		graphics->FillRectangle(Brushes::Green, rectVerdeOscuro);
		graphics->DrawString("Stock lleno", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, y);
		// Verde claro
		y += separacionY;
		Rectangle rectVerdeClaro = Rectangle(10, y, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectVerdeClaro);
		graphics->FillRectangle(Brushes::LightGreen, rectVerdeClaro);
		graphics->DrawString("Stock en rango", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, y);
		// Amarillo
		y += separacionY;
		Rectangle rectAmarillo = Rectangle(10, y, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectAmarillo);
		graphics->FillRectangle(Brushes::Yellow, rectAmarillo);
		graphics->DrawString("Stock bajo", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, y);
		// Rojo
		y += separacionY;
		Rectangle rectRojo = Rectangle(10, y, 15, 15);
		graphics->DrawRectangle(Pens::Black, rectRojo);
		graphics->FillRectangle(Brushes::Red, rectRojo);
		graphics->DrawString("Stock agotado", gcnew System::Drawing::Font("Arial", 8), Brushes::Black, 30, y);
	}

		   // panel1_Paint: NO dibujar aquí barras largas que representen cada stock.
		   // Solo dejarlo vacío o usar para debug. Mantenerlo para compatibilidad si necesitas
		   // dibujar algún overlay; por ahora no entrenará solapamientos con controles.
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		// Intencionalmente vacío para evitar solapamiento con los controles dinámicos.
	}
	};
}