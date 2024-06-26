#pragma once
#include "product_manager_class.h"
#include <limits> // Agrega esta inclusi�n para usar numeric_limits
#include <limits> // Para obtener el l�mite de valores enteros

void addNewProduct(GESTION_PRODUCTOS& manager) {
    string codigo, nombre, marca, modelo, material, color;
    double precio, ancho, alto, largo, peso;
    int garantia;

    cin.ignore(); // Limpiar el b�fer de entrada antes de getline

    cout << YELLOW_COLOR << "Ingrese el c�digo del nuevo producto: " << RESET_COLOR;
    getline(cin, codigo);
    if (codigo.empty()) {
        cout << endl << MAGENTA_COLOR << "El c�digo del producto no puede estar vac�o." << RESET_COLOR << DOUBLE_SPACE;
    }
    else if (manager.hasCodigo(codigo)) {
        cout << endl << MAGENTA_COLOR << "El c�digo del producto ya existe." << RESET_COLOR << DOUBLE_SPACE;
        cout << YELLOW_COLOR << "Ingrese nuevamente el c�digo: " << RESET_COLOR;
        getline(cin, codigo);
    }

    cout << YELLOW_COLOR << "Ingrese el nombre del nuevo producto: " << RESET_COLOR;
    getline(cin, nombre);
    if (nombre.empty() || any_of(nombre.begin(), nombre.end(), [](char c) { return !isalpha(c) && c != ' '; })) {
        cout << RED_COLOR << "El nombre del producto solo puede contener letras y espacios." << RESET_COLOR << endl;
        cout << YELLOW_COLOR << "Ingrese nuevamente el nombre: " << RESET_COLOR;
        getline(cin, nombre);
    }

    cout << YELLOW_COLOR << "Ingrese la marca del nuevo producto: " << RESET_COLOR;
    getline(cin, marca);
    if (marca.empty() || any_of(marca.begin(), marca.end(), [](char c) { return !isalpha(c) && c != ' '; })) {
        cout << RED_COLOR << "La marca del producto solo puede contener letras y espacios." << RESET_COLOR << endl;
        cout << YELLOW_COLOR << "Ingrese nuevamente la marca: " << RESET_COLOR;
        getline(cin, marca);
    }

    cout << YELLOW_COLOR << "Ingrese el precio del nuevo producto: " << RESET_COLOR;
    while (!(cin >> precio) || precio <= 0) {
        cout << endl << MAGENTA_COLOR << "El precio del producto debe ser un n�mero positivo." << RESET_COLOR << DOUBLE_SPACE;
        cin.clear(); // Limpia los bits de error
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); // Ignora la entrada incorrecta
        cout << YELLOW_COLOR << "Ingrese nuevamente el precio: " << RESET_COLOR;
    }

    cout << YELLOW_COLOR << "Ingrese el modelo del nuevo producto: " << RESET_COLOR;
    cin.ignore();
    getline(cin, modelo);
    if (modelo.empty() || any_of(modelo.begin(), modelo.end(), [](char c) { return !isalnum(c); })) {
        cout << MAGENTA_COLOR << "El modelo del producto solo puede contener letras y n�meros." << RESET_COLOR << endl;
        cout << YELLOW_COLOR << "Ingrese nuevamente el modelo: " << RESET_COLOR;
        getline(cin, modelo);   
    }

    cout << YELLOW_COLOR << "Ingrese el ancho (cm) del nuevo producto: " << RESET_COLOR;
    cin >> ancho;
    if (ancho <= 0 || cin.fail()) {
        cout << RED_COLOR << "El ancho del producto debe ser un n�mero positivo." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); // Ignora la entrada incorrecta
        cout << YELLOW_COLOR << "Ingrese nuevamente el ancho: " << RESET_COLOR;
        cin.ignore();
        cin >> ancho;
    }

    cout << YELLOW_COLOR << "Ingrese el alto (cm) del nuevo producto: " << RESET_COLOR;
    cin >> alto;
    if (alto <= 0 || cin.fail()) {
        cout << RED_COLOR << "El alto del producto debe ser un n�mero positivo." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); // Ignora la entrada incorrecta
        cout << YELLOW_COLOR << "Ingrese nuevamente el alto: " << RESET_COLOR;
        cin.ignore();
        cin >> alto;
    }

    cout << YELLOW_COLOR << "Ingrese el largo (cm) del nuevo producto: " << RESET_COLOR;
    cin >> largo;
    if (largo <= 0 || cin.fail()) {
        cout << RED_COLOR << "El largo del producto debe ser un n�mero positivo." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); // Ignora la entrada incorrecta
        cout << YELLOW_COLOR << "Ingrese nuevamente el largo: " << RESET_COLOR;
        cin.ignore();
        cin >> largo;
    }

    cout << YELLOW_COLOR << "Ingrese el peso (Kg) del nuevo producto: " << RESET_COLOR;
    cin >> peso;
    if (peso <= 0 || cin.fail()) {
        cout << RED_COLOR << "El peso del producto debe ser un n�mero positivo." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); // Ignora la entrada incorrecta
        cout << YELLOW_COLOR << "Ingrese nuevamente el peso: " << RESET_COLOR;
        cin.ignore();
        cin >> peso;
    }

    cout << YELLOW_COLOR << "Ingrese el material del nuevo producto: " << RESET_COLOR;
    cin.ignore();
    getline(cin, material);
    if (material.empty() || !all_of(material.begin(), material.end(), ::isalnum)) {
        cout << RED_COLOR << "El material del producto solo puede contener letras y n�meros." << RESET_COLOR << endl;
        cout << YELLOW_COLOR << "Ingrese nuevamente el material: " << RESET_COLOR;
        getline(cin, material);
    }

    cout << YELLOW_COLOR << "Ingrese el color del nuevo producto: " << RESET_COLOR;
    getline(cin, color);
    if (color.empty() || !all_of(color.begin(), color.end(), ::isalpha)) {
        cout << RED_COLOR << "El color del producto solo puede contener letras." << RESET_COLOR << endl;
        cout << YELLOW_COLOR << "Ingrese nuevamente el color: " << RESET_COLOR;
        getline(cin, color);        
    }

    cout << YELLOW_COLOR << "Ingrese la garantia (meses) del nuevo producto: " << RESET_COLOR;
    cin >> garantia;
    if (garantia <= 0 || cin.fail()) {
        cout << RED_COLOR << "La garant�a del producto debe ser un n�mero entero positivo." << RESET_COLOR << endl;
        cin.clear();
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n'); // Ignora la entrada incorrecta
        cout << YELLOW_COLOR << "Ingrese nuevamente la garant�a: " << RESET_COLOR;
        cin.ignore();
        cin >> garantia;
    }

    PRODUCTO nuevoProducto(codigo, nombre, marca, precio, modelo, ancho, alto, largo, peso, material, color, garantia);
    manager.agregarProducto(nuevoProducto);

    // Mostrar mensaje de �xito
    ShowConsoleCursor(false);
    cout << DOUBLE_SPACE << GREEN_COLOR << "Nuevo producto agregado correctamente." << RESET_COLOR << endl;
    _sleep(1500); // Esperar 1.5 segundos antes de limpiar la pantalla
}

void updateProductProcedure(GESTION_PRODUCTOS& manager) {
    string codigo;
    double nuevoPrecio = 0;
    string nuevoCodigo;
    int nuevaGarantia;

    cout << YELLOW_COLOR << "Ingrese el c�digo del producto que desea actualizar: " << RESET_COLOR;
    cin.ignore();
    getline(cin, codigo);

    if (!manager.existeProducto(codigo)) {
        ShowConsoleCursor(false);
        cout << endl << MAGENTA_COLOR << "El producto con el c�digo ingresado no existe." << RESET_COLOR << endl;
        _sleep(1500);
        return;
    }

    cout << YELLOW_COLOR << "Ingrese el precio del nuevo producto: " << RESET_COLOR;
    while (!(cin >> nuevoPrecio) || nuevoPrecio <= 0) {
        if (cin.fail()) {
            // Limpiar el estado de error y descartar la entrada inv�lida
            cin.clear();
            cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
            cout << endl << MAGENTA_COLOR << "Debe ingresar un n�mero v�lido para el precio." << RESET_COLOR << DOUBLE_SPACE;
        }
        else {
            // Verificar si la entrada contiene caracteres no num�ricos
            bool contieneNoNumeros = false;
            string entradaInvalida;
            getline(cin, entradaInvalida);

            for (char c : entradaInvalida) {
                if (!isdigit(c)) {
                    contieneNoNumeros = true;
                    break;
                }
            }

            if (contieneNoNumeros) {
                cout << endl << MAGENTA_COLOR << "El precio del producto debe ser un n�mero positivo." << RESET_COLOR << DOUBLE_SPACE;
            }
            else {
                cout << endl << MAGENTA_COLOR << "El precio del producto debe ser un n�mero v�lido y positivo." << RESET_COLOR << DOUBLE_SPACE;
            }
        }
        cout << YELLOW_COLOR << "Ingrese nuevamente el precio: " << RESET_COLOR;
    }

    cin.ignore();

    cout << YELLOW_COLOR << "Ingrese el nuevo c�digo del producto: " << RESET_COLOR;
    getline(cin, nuevoCodigo);
    while (nuevoCodigo.empty() || manager.hasCodigo(nuevoCodigo)) {
        if (nuevoCodigo.empty()) {
            cout << endl << MAGENTA_COLOR << "El c�digo del producto no puede estar vac�o." << RESET_COLOR << DOUBLE_SPACE;
        }
        else {
            cout << endl << MAGENTA_COLOR << "El c�digo del producto ya existe." << RESET_COLOR << DOUBLE_SPACE;
        }
        cout << YELLOW_COLOR << "Ingrese nuevamente el c�digo: " << RESET_COLOR;
        getline(cin, nuevoCodigo);
    }

    cout << YELLOW_COLOR << "Ingrese la nueva garant�a (meses) del producto: " << RESET_COLOR;
    while (!(cin >> nuevaGarantia) || nuevaGarantia <= 0) {
        cout << endl << MAGENTA_COLOR << "La garant�a del producto debe ser un n�mero positivo." << RESET_COLOR << DOUBLE_SPACE;
        cin.clear();
        cin.ignore((std::numeric_limits<streamsize>::max)(), '\n');
        cout << YELLOW_COLOR << "Ingrese nuevamente la garant�a: " << RESET_COLOR;
    }

    manager.actualizarProducto(codigo, nuevoPrecio, nuevoCodigo, nuevaGarantia);
    
    ShowConsoleCursor(false);
    cout << DOUBLE_SPACE << GREEN_COLOR << "Producto actualizado correctamente";
    _sleep(1500);
}

void removeProductProcedure(GESTION_PRODUCTOS& manager) {
    string codigo;

    // Solicitar al usuario el c�digo del producto a eliminar
    cout << YELLOW_COLOR << "Ingrese el c�digo del producto que desea eliminar: " << RESET_COLOR;
    cin.ignore(); // Limpiar el b�fer de entrada antes de getline
    getline(cin, codigo);

    ShowConsoleCursor(false); // Ocultar el cursor para evitar errores de visualizaci�n

    // Verificar si el producto existe antes de eliminarlo
    if (manager.existeProducto(codigo)) {
        // Eliminar el producto del gestor de productos
        manager.eliminarProducto(codigo);

        // Mostrar mensaje de �xito
        cout << DOUBLE_SPACE << GREEN_COLOR << "Producto eliminado correctamente." << endl;
        _sleep(1500); // Esperar 1.5 segundos antes de limpiar la pantalla
    }
    else {
        // Mostrar mensaje de error si el producto no existe
        cout << DOUBLE_SPACE << MAGENTA_COLOR << "Error: El producto con c�digo " << codigo << " no existe." << endl;
        _sleep(1500); // Esperar 1.5 segundos antes de limpiar la pantalla
    }
}

void searchProduct(GESTION_PRODUCTOS& manager) {
    string codigo;

    // Solicitar al usuario el c�digo del producto a buscar
    ShowConsoleCursor(true);
    cout << YELLOW_COLOR << "Ingrese el c�digo del producto que desea buscar: " << RESET_COLOR;
    cin.ignore(); // Limpiar el b�fer de entrada antes de getline
    getline(cin, codigo);
    cout << endl;

    // Buscar y mostrar la informaci�n del producto
    manager.buscarYMostrarProducto(codigo);
}